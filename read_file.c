/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:50:10 by acan              #+#    #+#             */
/*   Updated: 2024/04/18 04:27:34 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void get_lines(char *file, t_data *data)
{
    int     fd;
    char    *line_nl;
    char    *line;

    fd = open(file, O_RDONLY);
    line_nl = get_next_line(fd);
    if (!line_nl)
        printerror("Empty file.");
    while (line_nl)
    {
        line = ft_strtrim(line_nl, "\n");
        free(line_nl);
        data->file = double_strjoin(data->file, line);
        line_nl = get_next_line(fd); 
    }
    close(fd);
}

static int init_nswe(char **texture, char *line)
{   
    int fd;
    
    if (*texture != NULL)
        printerror("Duplicate texture.");
    *texture = ft_strtrim(line + 3, " \n");
    extension_check(*texture, ".xpm");
    fd = open(*texture, O_RDONLY);
    if (fd < 0)
        printerror("Invalid texture path.");
    return 1;
}

static int init_fc(int **texture, char *line)
{    
    char    **rgb;
    char    *path;
    int     i;
    
    if (*texture != NULL)
        printerror("Duplicate texture.");
    printf("burada");
    path = ft_strtrim(line + 2, " \n");
    if (*path == ',')
        printerror("Invalid RGB value.");
    rgb = ft_split(path, ',');
    *texture = malloc(sizeof(int) * 3);
    i = -1;
    while (rgb[++i] && i < 3)
    {
        (*texture)[i] = atoi_for_rgb(rgb[i]);
        free(rgb[i]);
    }
    if (i != 3)
        printerror("Invalid RGB value.");
    free(rgb);
    free(path);
    return 1;
}

static void match_line_to_texture(t_data *data, char *line, int *count)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
        *count += init_nswe(&data->textures->no, line);
    else if (ft_strncmp(line, "SO ", 3) == 0)
        *count += init_nswe(&data->textures->so, line);
    else if (ft_strncmp(line, "WE ", 3) == 0)
        *count += init_nswe(&data->textures->we, line);
    else if (ft_strncmp(line, "EA ", 3) == 0)
        *count += init_nswe(&data->textures->ea, line);
    else if (ft_strncmp(line, "F ", 2) == 0)
        *count += init_fc(&data->textures->f, line);
    else if (ft_strncmp(line, "C ", 2) == 0)
        *count += init_fc(&data->textures->c, line);
    else if (own_strcmp(*data->file, "\0"))
        printerror("Invalid file content.");
}

static void check_textures(t_data *data)
{
    int     texturecount;
    char     *trimmedline;
    
    texturecount = 0;
    while (*data->file)
    {
        trimmedline = ft_strtrim(*data->file, " \n");
        match_line_to_texture(data, trimmedline, &texturecount);
        free(*data->file);
        free(trimmedline);
        data->file++;
        if (texturecount == 6)
            break;
    }
    if (texturecount != 6)
        printerror("Missing texture.");
}

void    read_file(char *file, t_data *data)
{
    get_lines(file, data);
    check_textures(data);
    //check_map(data);
}