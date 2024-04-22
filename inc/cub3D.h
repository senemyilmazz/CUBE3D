/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:35:51 by acan              #+#    #+#             */
/*   Updated: 2024/04/20 15:35:16 by senyilma         ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	size_t	width;
	size_t	height;
}			t_map;

typedef struct s_player
{
	char	pos_dir;
	int		pos_x;
	int		pos_y;
}			t_player;

typedef struct s_data
{
	char			**file;
	t_texture		*textures;
	t_map			*map;
	t_player		*player;
}					t_data;

// FUNCTIONS

// FILE_CHECK_FUNCTIONS
void		check_file(char *file, t_data *data);
void		check_map(t_data *data);
void		check_textures(t_data *data);
void		match_line_to_texture(t_data *data, int *count);

//	CHECK_MAP_UTIL_FUNCTIONS
int			find_max_len(char **content);
char		*add_null(char *line, int max_len);
void		backup_map(char **map, char ***backupmap);
void		check_line_is_not_empty(char *line);
void		check_char_is_valid(char c);
void		check_player_is_single(int i, int j, t_data *data);
void		check_surround_by_walls(char **map, int i, int j);

//FILE_PATH_UTIL_FUNCTIONS
void		open_check(char *file);
void		extension_check(char *file, char *extension);
void		hidden_file_check(char *file);

// UTIL_FUNCTIONS
void		printerror(char *error);
char		**double_strjoin(char **oldlist, char *str);
char		*own_strjoin(char *s1, char *s2);
int			own_strcmp(const char *s1, const char *s2);
void		free_and_set_null(char *str);
void		double_free(char **str);


#endif