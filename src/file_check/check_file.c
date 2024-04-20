/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:50:10 by acan              #+#    #+#             */
/*   Updated: 2024/04/20 15:36:26 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	check_file_path(char *file)
{
	open_check(file);
	hidden_file_check(file);
	extension_check(file, ".cub");
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
	check_file_path(file);
	get_lines(file, data);
	check_textures(data);
	check_map(data);
}
