/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:58:13 by senyilma          #+#    #+#             */
/*   Updated: 2024/04/18 16:19:53 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_existance_of_map(t_data *data)
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
		printerror("No map found.");
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

	map_backup(data->map, &backupmap);
	i = -1;
	while (backupmap[++i])
	{
		if (!own_strcmp(data->map[i], "\0"))
			printerror("Invalid map.");
		j = -1;
		while (backupmap[i][++j])
		{
			if (!ft_strchr("NSWE01 ", data->map[i][j]))
				printerror("Invalid map.");
			if (ft_strchr("NSWE0", backupmap[i][j]))
				floodfill(backupmap, i, j, data);
		}
	}
	double_free(backupmap);
	if (data->player->x == -1)
		printerror("Player not found.");
}

void	check_map(t_data *data)
{
	check_existance_of_map(data);
	read_map(data);
	check_map_is_valid(data);
}
