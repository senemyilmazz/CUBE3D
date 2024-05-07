/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:54:58 by senyilma          #+#    #+#             */
/*   Updated: 2024/05/07 17:11:12 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static int	atoi_for_rgb(const char *str)
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
			printerror("Invalid texture : Invalid RGB value detected.");
		count++;
	}
	while (code[count] >= '0' && code[count] <= '9')
	{
		result = (result * 10) + code[count] - '0';
		if (result > 255)
			printerror("Invalid texture : Invalid RGB value detected.");
		count++;
	}
	if (code[count] != '\0')
		printerror("Invalid texture : Invalid RGB value detected.");
	free_and_set_null(code);
	return (result);
}

static int	init_nswe(char **texture, char *line)
{
	if (*texture != NULL)
		printerror("Invalid texture : Duplicate texture detected.");
	*texture = ft_strtrim(line + 3, " \n");
	check_file_path(*texture, ".xpm");
	return (1);
}

static int	init_fc(int **texture, char *line)
{
	char	**rgb;
	char	*path;
	int		i;

	if (*texture != NULL)
		printerror("Invalid texture : Duplicate texture detected.");
	path = ft_strtrim(line + 2, " \n");
	if (*path == ',')
		printerror("Invalid texture : Invalid RGB value detected.");
	rgb = ft_split(path, ',');
	*texture = malloc(sizeof(int) * 3);
	if (!*texture)
		printerror("Allocation error!");
	i = -1;
	while (rgb[++i] && i < 3)
		(*texture)[i] = atoi_for_rgb(rgb[i]);
	if (i != 3)
		printerror("Invalid texture : Invalid RGB value detected.");
	double_free(rgb);
	free_and_set_null(path);
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
		printerror("Invalid texture : Undefined file content detected.");
	free_and_set_null(trimmedline);
}

void	check_textures(t_data *data)
{
	int	texturecount;

	texturecount = 0;
	while (*data->file)
	{
		match_line_to_texture(data, &texturecount);
		free_and_set_null(*data->file);
		data->file++;
		if (texturecount == 6)
			break ;
	}
	if (texturecount != 6)
		printerror("Invalid texture : Missing texture detected.");
}
