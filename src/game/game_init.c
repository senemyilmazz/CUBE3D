/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:05:10 by acan              #+#    #+#             */
/*   Updated: 2024/05/09 20:05:24 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	start_variables(t_data *data)
{
	data->game->mlx = NULL;
	data->game->win = NULL;
	data->game->img = NULL;
	data->game->addr = NULL;
	data->textures->size = 0;
	data->textures->img_n = NULL;
	data->textures->img_s = NULL;
	data->textures->img_e = NULL;
	data->textures->img_w = NULL;
	data->textures->addr_n = NULL;
	data->textures->addr_s = NULL;
	data->textures->addr_e = NULL;
	data->textures->addr_w = NULL;
	data->keys->w = 0;
	data->keys->a = 0;
	data->keys->s = 0;
	data->keys->d = 0;
	data->keys->left = 0;
	data->keys->right = 0;
	data->game->rot_speed = 0.03;
	data->game->move_speed = 0.032;
}

static void	set_game_image(t_data *data)
{
	data->textures->img_n = mlx_xpm_file_to_image(data->game->mlx,
			data->textures->no, &data->textures->size, &data->textures->size);
	data->textures->img_s = mlx_xpm_file_to_image(data->game->mlx,
			data->textures->so, &data->textures->size, &data->textures->size);
	data->textures->img_e = mlx_xpm_file_to_image(data->game->mlx,
			data->textures->ea, &data->textures->size, &data->textures->size);
	data->textures->img_w = mlx_xpm_file_to_image(data->game->mlx,
			data->textures->we, &data->textures->size, &data->textures->size);
	if (!data->textures->img_e || !data->textures->img_w
		|| !data->textures->img_s || !data->textures->img_n)
		printerror("Textures cannot created or files is not valid.");
	data->textures->addr_n = (int *)mlx_get_data_addr(data->textures->img_n,
			&data->game->bpp, &data->game->size_line, &data->game->endian);
	data->textures->addr_s = (int *)mlx_get_data_addr(data->textures->img_s,
			&data->game->bpp, &data->game->size_line, &data->game->endian);
	data->textures->addr_e = (int *)mlx_get_data_addr(data->textures->img_e,
			&data->game->bpp, &data->game->size_line, &data->game->endian);
	data->textures->addr_w = (int *)mlx_get_data_addr(data->textures->img_w,
			&data->game->bpp, &data->game->size_line, &data->game->endian);
	if (!data->textures->addr_e || !data->textures->addr_w
		|| !data->textures->addr_s || !data->textures->addr_n)
		printerror("Textures cannot be addressed.");
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->game->mlx, data->game->win);
	exit(0);
	return (0);
}

void	game(t_data *data)
{
	start_variables(data);
	data->game->mlx = mlx_init();
	data->game->win = mlx_new_window(data->game->mlx, WIDTH, HEIGHT, "cub3D");
	data->game->img = mlx_new_image(data->game->mlx, WIDTH, HEIGHT);
	data->game->addr = (int *)mlx_get_data_addr(data->game->img,
			&data->game->bpp, &data->game->size_line, &data->game->endian);
	if (!data->game->addr || !data->game->img
		|| !data->game->mlx || !data->game->win)
		printerror("Game cannot be created.");
	set_game_image(data);
	mlx_loop_hook(data->game->mlx, draw_textures, data);
	mlx_hook(data->game->win, 2, 0, key_press, data);
	mlx_hook(data->game->win, 3, 0, key_release, data);
	mlx_hook(data->game->win, 17, 0, close_window, data);
	mlx_loop(data->game->mlx);
}
