/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:54:58 by senyilma          #+#    #+#             */
/*   Updated: 2024/04/18 15:46:04 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_nswe(char **texture, char *line)
{
	//int fd;
	if (*texture != NULL)
		printerror("Duplicate texture.");
	*texture = ft_strtrim(line + 3, " \n");
	extension_check(*texture, ".xpm");
	//fd = open(*texture, O_RDONLY);
	//if (fd < 0)
	//    printerror("Invalid texture path.");
	return (1);
}

static int	init_fc(int **texture, char *line)
{
	char	**rgb;
	char	*path;
	int		i;

	if (*texture != NULL)
		printerror("Duplicate texture.");
	path = ft_strtrim(line + 2, " \n");
	if (*path == ',')
		printerror("Invalid RGB value.");
	rgb = ft_split(path, ',');
	*texture = malloc(sizeof(int) * 3);
	i = -1;
	while (rgb[++i] && i < 3)
		(*texture)[i] = atoi_for_rgb(rgb[i]);
	if (i != 3)
		printerror("Invalid RGB value.");
	double_free(rgb);
	free(path);
	return (1);
}

void	match_line_to_texture(t_data *data, int *count)
{
	char	*trimmedline;

	trimmedline = ft_strtrim(*data->file, " ");
	if (ft_strncmp(trimmedline, "NO ", 3) == 0)
		*count += init_nswe(&data->textures->no, trimmedline);
	else if (ft_strncmp(trimmedline, "SO ", 3) == 0)
		*count += init_nswe(&data->textures->so, trimmedline);
	else if (ft_strncmp(trimmedline, "WE ", 3) == 0)
		*count += init_nswe(&data->textures->we, trimmedline);
	else if (ft_strncmp(trimmedline, "EA ", 3) == 0)
		*count += init_nswe(&data->textures->ea, trimmedline);
	else if (ft_strncmp(trimmedline, "F ", 2) == 0)
		*count += init_fc(&data->textures->f, trimmedline);
	else if (ft_strncmp(trimmedline, "C ", 2) == 0)
		*count += init_fc(&data->textures->c, trimmedline);
	else if (own_strcmp(*data->file, "\0"))
		printerror("Invalid file content.");
	free(trimmedline);
}

void	check_textures(t_data *data)
{
	int	texturecount;

	texturecount = 0;
	while (*data->file)
	{
		match_line_to_texture(data, &texturecount);
		free(*data->file);
		data->file++;
		if (texturecount == 6)
			break ;
	}
	if (texturecount != 6)
		printerror("Missing texture.");
}
