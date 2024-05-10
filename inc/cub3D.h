/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:35:51 by acan              #+#    #+#             */
/*   Updated: 2024/05/10 15:15:08 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// INCLUDES
# include "../mlx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "fcntl.h"
# include "stdio.h"
# include "math.h"	

# define WIDTH 1920
# define HEIGHT 1080

// STRUCTS
typedef struct s_texture
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			*f;
	int			*c;
	void		*img_n;
	void		*img_s;
	void		*img_w;
	void		*img_e;
	int			*addr_n;
	int			*addr_s;
	int			*addr_w;
	int			*addr_e;
	int			size;
}				t_texture;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
}				t_player;

typedef struct s_view
{
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		old_dir_x;
	double		old_plane_x;
}				t_view;

typedef struct s_ray
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			pos_x;
	int			pos_y;
	double		deltadist_x;
	double		deltadist_y;
	double		sidedist_x;
	double		sidedist_y;
	int			side;
	int			step_x;
	int			step_y;
	double		plane_wall_dist;
	int			draw_height;
	int			draw_start;
	int			draw_end;
	double		hit_x;
	int			tex_x;
	double		unit_per_pix;
	int			tex_y;
	double		tex_y_next;
}				t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			bpp;
	int			size_line;
	int			endian;
	double		move_speed;
	double		rot_speed;
}				t_game;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			escape;
	int			left;
	int			right;
}				t_keys;

typedef struct s_data
{
	char		**file;
	char		**map;
	t_texture	*textures;
	t_player	*player;
	t_game		*game;
	t_view		*view;
	t_ray		*ray;
	t_keys		*keys;
}				t_data;

// GAME FUNCTIONS
void			game(t_data *data);
int				draw_textures(t_data *data);
void			var_set(t_data *data, int width);
void			calculate_ray_piece(t_data *data);
void			side_hit(t_data *data);
void			calculate_side_distance(t_data *data);
void			set_texture_starting_pixel(t_data *data);

int				key_press(int key, t_data *data);
int				key_release(int key, t_data *data);
void			move_player(t_data *data);
void			cam_right(t_data *data);
void			cam_left(t_data *data);

// FILE_CHECK_FUNCTIONS
void			check_file_path(char *file, char *extension);
void			check_file(char *file, t_data *data);
void			check_map(t_data *data);
void			check_textures(t_data *data);

//	CHECK_MAP_UTIL_FUNCTIONS
int				find_max_len(char **content);
char			*add_null(char *line, int max_len);
void			set_view_dir_and_plane(t_data *data, char dir);
void			backup_map(char **map, char ***backupmap);
void			check_line_is_not_empty(char *line);
void			check_char_is_valid(char c);
void			check_player_is_single(int i, int j, t_data *data);
void			check_surround_by_walls(char **map, int i, int j);
void			set_view_dir_and_plane(t_data *data, char c);
void			match_line_to_texture(t_data *data, int *count);

// CHECK_FILE_PATH_FUNCTIONS
void			open_check(char *file);
void			extension_check(char *file, char *extension);
void			hidden_file_check(char *file);

// UTIL_FUNCTIONS
void			printerror(char *error);
char			**double_strjoin(char **oldlist, char *str);
char			*own_strjoin(char *s1, char *s2);
int				own_strcmp(const char *s1, const char *s2);
void			free_and_set_null(char *str);
void			double_free(char **str);

#endif