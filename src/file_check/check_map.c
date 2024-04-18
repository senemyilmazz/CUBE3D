/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:58:13 by senyilma          #+#    #+#             */
/*   Updated: 2024/04/18 19:55:13 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	check_map_is_exist(t_data *data)
{
	while (*data->file)
	{
		if (ft_strnstr(*data->file, "111", 3) != 0)
			break ;
		match_line_to_texture(data, NULL);
		free(*data->file);
		data->file++;
	}
	if (!*data->file)
		printerror("No map exist.");
}

static void	read_map(t_data *data)
{
	while (*data->file)
	{
		data->map = double_strjoin(data->map, *data->file);
		data->file++;
	}
}

static void	check_map_is_valid(t_data *data)
{
	int		i;
	int		j;
	char	**backupmap;

	backup_map(data->map, &backupmap);
	i = -1;
	while (backupmap[++i])
	{
		check_line_is_not_empty(data->map[i]);
		j = -1;
		while (backupmap[i][++j])
		{
			check_char_is_valid(data->map[i][j]);
			check_player_singularity(i, j, data);
			if (ft_strchr("NESW0", backupmap[i][j]))
				check_surround_by_walls(backupmap, i, j);
		}
	}
	double_free(backupmap);
}

void	check_map(t_data *data)
{
	check_map_is_exist(data);
	read_map(data);
	check_map_is_valid(data);
}
