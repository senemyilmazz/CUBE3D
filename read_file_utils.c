/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:16:32 by senyilma          #+#    #+#             */
/*   Updated: 2024/04/18 16:11:42 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	atoi_for_rgb(const char *str)
{
	size_t	count;
	int		result;
	char	*code;

	count = 0;
	result = 0;
	code = ft_strtrim(str, " ");
	if (code[count] == '-' || code[count] == '+')
	{
		if (code[count] == '-')
			printerror("Invalid RGB value.");
		count++;
	}
	while (code[count] >= '0' && code[count] <= '9')
	{
		result = (result * 10) + code[count] - '0';
		if (result > 255)
			printerror("Invalid RGB value.");
		count++;
	}
	if (code[count] != '\0')
		printerror("Invalid RGB value.");
	free(code);
	return (result);
}

void	playercounter(int i, int j, t_data *data)
{
	static int	playercount;

	playercount++;
	if (playercount > 1)
		printerror("Multiplayer cannot be allowed.");
	data->player->x = i;
	data->player->y = j;
}

void	floodfill(char **map, int i, int j, t_data *data)
{
	if (!map[i] || !map[i][j] || map[i][j] == ' ')
		printerror("Map is not closed.");
	if (map[i][j] == '1' || map[i][j] == '.')
		return ;
	if (ft_strchr("NSWE", map[i][j]))
		playercounter(i, j, data);
	map[i][j] = '.';
	floodfill(map, i - 1, j, data);
	floodfill(map, i, j - 1, data);
	floodfill(map, i + 1, j, data);
	floodfill(map, i, j + 1, data);
}

void	map_backup(char **map, char ***backupmap)
{
	int	i;

	i = -1;
	*backupmap = NULL;
	while (map[++i])
		(*backupmap) = double_strjoin((*backupmap), ft_strdup(map[i]));
}
