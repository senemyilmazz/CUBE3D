/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:50:10 by acan              #+#    #+#             */
/*   Updated: 2024/05/07 17:26:01 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	start_variables(t_data *data)
{
	data->file = NULL;
	data->map = NULL;
	data->textures->no = NULL;
	data->textures->so = NULL;
	data->textures->we = NULL;
	data->textures->ea = NULL;
	data->textures->f = NULL;
	data->textures->c = NULL;
}

static void	get_lines(char *file, t_data *data)
{
	int		fd;
	char	*line_nl;
	char	*line;

	fd = open(file, O_RDONLY);
	line_nl = get_next_line(fd);
	if (!line_nl)
		printerror("Empty file.");
	while (line_nl)
	{
		line = ft_strtrim(line_nl, "\n");
		free_and_set_null(line_nl);
		data->file = double_strjoin(data->file, line);
		line_nl = get_next_line(fd);
	}
	close(fd);
}

void	check_file(char *file, t_data *data)
{
	start_variables(data);
	check_file_path(file, ".cub");
	get_lines(file, data);
	check_textures(data);
	check_map(data);
}
