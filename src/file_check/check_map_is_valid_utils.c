/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_valid_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:16:32 by senyilma          #+#    #+#             */
/*   Updated: 2024/05/07 18:43:38 by senyilma         ###   ########.fr       */
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
	if (*line == '\0')
		printerror("Invalid map : Empty line detected!");
}

void	check_char_is_valid(char c)
{
	if (!ft_strchr("NSWE01 ", c))
		printerror("Invalid map : Undefined character detected!");
}

void	check_player_is_single(int i, int j, t_data *data)
{
	static int	playercount;

	if (ft_strchr("NSWE", data->map[i][j]))
	{
		playercount++;
		data->player->pos_x = j + 0.5;
		data->player->pos_y = i + 0.5;
		set_view_dir_and_plane(data, data->map[i][j]);
	}
	if (playercount > 1)
		printerror("Invalid map : Multiplayer cannot be allowed!");
	if (!data->map[i + 1] && !data->map[i][j + 1]
		&& data->player->pos_x == -1)
		printerror("Invalid map : Player not found!");
}

void	check_surround_by_walls(char **map, int i, int j)
{
	if (i < 0 || j < 0 || !map[i] || !map[i][j] || map[i][j] == ' ')
		printerror("Invalid map : Unclosed map detected!");
	if (map[i][j] == '1' || map[i][j] == '.')
		return ;
	map[i][j] = '.';
	check_surround_by_walls(map, i - 1, j);
	check_surround_by_walls(map, i, j - 1);
	check_surround_by_walls(map, i + 1, j);
	check_surround_by_walls(map, i, j + 1);
}
