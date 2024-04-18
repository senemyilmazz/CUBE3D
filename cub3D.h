/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:35:51 by acan              #+#    #+#             */
/*   Updated: 2024/04/18 03:30:53 by senyilma         ###   ########.fr       */
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

typedef struct s_data
{
	char	**file;
	char	**map;
	t_texture	*textures;
}			t_data;

// FUNCTIONS

// FILE_CHECK_FUNCTIONS
void    	file_check(char *file);
void		extension_check(char *file, char *extension);

// UTIL_FUNCTIONS
void		printerror(char *error);
char    	**double_strjoin(char **oldlist, char *str);
int			own_strcmp(const char *s1, const char *s2);
int			atoi_for_rgb(const char *str);

// READ_FILE_FUNCTIONS
void    	read_file(char *file, t_data *data);

#endif