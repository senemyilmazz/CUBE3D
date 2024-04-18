/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:16:32 by senyilma          #+#    #+#             */
/*   Updated: 2024/04/18 19:14:12 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	backup_map(char **map, char ***backupmap)
{
	int	i;

	i = -1;
	*backupmap = NULL;
	while (map[++i])
		(*backupmap) = double_strjoin((*backupmap), ft_strdup(map[i]));
}

void	check_line_is_not_empty(char *line)
{
	if (!own_strcmp(line, "\0"))
		printerror("Invalid map : Empty line detected!");
}

void	check_char_is_valid(char c)
{
	if (!ft_strchr("NSWE01 ", c))
		printerror("Invalid map : Undefined character detected!");
}

void	check_player_singularity(int i, int j, t_data *data)
{
	static int	playercount;

	if (ft_strchr("NSWE", data->map[i][j]))
	{
		playercount++;
		data->player->x = i;
		data->player->y = j;
	}
	if (playercount > 1)
		printerror("Invalid map : Multiplayer cannot be allowed!");
	if (!data->map[i + 1] && !data->map[i][j + 1] && data->player->x == -1)
		printerror("Invalid map : Player not found!");
}

void	check_surround_by_walls(char **map, int i, int j)
{
	if (!map[i] || !map[i][j] || map[i][j] == ' ')
		printerror("Invalid map : Unclosed map detected!");
	if (map[i][j] == '1' || map[i][j] == '.')
		return ;

	map[i][j] = '.';
	check_wall_is_close(map, i - 1, j);
	check_wall_is_close(map, i, j - 1);
	check_wall_is_close(map, i + 1, j);
	check_wall_is_close(map, i, j + 1);
}
