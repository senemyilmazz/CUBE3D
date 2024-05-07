/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:58:13 by senyilma          #+#    #+#             */
/*   Updated: 2024/05/07 13:56:27 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	check_map_is_exist(t_data *data)
{
	while (*data->file)
	{
		if (ft_strchr(*data->file, '1'))
			break ;
		match_line_to_texture(data, NULL);
		free_and_set_null(*data->file);
		data->file++;
	}
	if (!*data->file)
		printerror("No map exist.");
}

static void	read_map(t_data *data)
{
	char	*line;
	int		weight;

	weight = find_max_len(data->file);
	while (*data->file)
	{
		line = add_null(*data->file, weight);
		data->map = double_strjoin(data->map, line);
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
		check_line_is_not_empty(backupmap[i]);
		j = -1;
		while (backupmap[i][++j])
		{
			check_char_is_valid(data->map[i][j]);
			check_player_is_single(i, j, data);
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
