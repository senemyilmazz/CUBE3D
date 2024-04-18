/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:35:51 by acan              #+#    #+#             */
/*   Updated: 2024/04/18 15:47:33 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// INCLUDES
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "fcntl.h"
# include "stdio.h"

// STRUCTS
typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
}			t_texture;

typedef struct s_koordinate
{
	int		x;
	int		y;
}			t_koordinate;

typedef struct s_data
{
	char			**file;
	char			**map;
	t_texture		*textures;
	t_koordinate	*player;
}					t_data;

// FUNCTIONS

// FILE_CHECK_FUNCTIONS
void		file_check(char *file);
void		extension_check(char *file, char *extension);
// UTIL_FUNCTIONS
void		printerror(char *error);
char		**double_strjoin(char **oldlist, char *str);
int			own_strcmp(const char *s1, const char *s2);
void		double_free(char **str);
// READ_FILE_FUNCTIONS
void		read_file(char *file, t_data *data);
int			atoi_for_rgb(const char *str);
void		playercounter(int i, int j, t_data *data);
void		floodfill(char **map, int i, int j, t_data *data);
void		map_backup(char **map, char ***backupmap);

//FILE_CONTENT_CHECK_FUNCTIONS
void		check_textures(t_data *data);
void		match_line_to_texture(t_data *data, int *count);
void		check_map(t_data *data);

#endif