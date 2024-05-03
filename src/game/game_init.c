/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <acan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:05:10 by acan              #+#    #+#             */
/*   Updated: 2024/05/03 18:40:20 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	start_values(t_data *data)
{
	data->ray->pos_x = 22;
	data->ray->pos_y = 12;
	data->game->x = 0;
	data->keys->w = 0;
	data->keys->a = 0;
	data->keys->s = 0;
	data->keys->d = 0;
	data->keys->left = 0;
	data->keys->right = 0;
	data->game->rot_speed = 0.03;
	data->game->move_speed = 0.032;
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->game->mlx, data->game->win);
	exit(0);
	return (0);
}

void	game_image(t_data *data)
{
	data->textures->img_n = mlx_xpm_file_to_image(data->game->mlx,
			data->textures->no, &data->game->x, &data->game->x);
	data->textures->img_s = mlx_xpm_file_to_image(data->game->mlx,
			data->textures->so, &data->game->x, &data->game->x);
	data->textures->img_e = mlx_xpm_file_to_image(data->game->mlx,
			data->textures->ea, &data->game->x, &data->game->x);
	data->textures->img_w = mlx_xpm_file_to_image(data->game->mlx,
			data->textures->we, &data->game->x, &data->game->x);
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

void	game(t_data *data)
{
	start_values(data);
	data->game->mlx = mlx_init();
	data->game->win = mlx_new_window(data->game->mlx, WIDTH, HEIGHT, "cub3D");
	data->game->img = mlx_new_image(data->game->mlx, WIDTH, HEIGHT);
	data->game->addr = (int *)mlx_get_data_addr(data->game->img,
			&data->game->bpp, &data->game->size_line, &data->game->endian);
	if (!data->game->addr || !data->game->img
		|| !data->game->mlx || !data->game->win)
		printerror("Game cannot be created.");
	game_image(data);
	mlx_hook(data->game->win, 17, 0, close_window, data);
	mlx_loop_hook(data->game->mlx, draw_content, data);
	mlx_hook(data->game->win, 2, 0, key_press, data);
	mlx_hook(data->game->win, 3, 0, key_release, data);
	mlx_loop(data->game->mlx);
}
