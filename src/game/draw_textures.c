/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:37:47 by acan              #+#    #+#             */
/*   Updated: 2024/05/10 14:20:40 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static int	set_color(int *rgb)
{
	int	color;

	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (color);
}

static void	sky_and_surface(t_data *data)
{
	int	loop1;
	int	loop2;
	int	sky_color;
	int	surface_color;

	sky_color = set_color(data->textures->c);
	surface_color = set_color(data->textures->f);
	loop1 = 0;
	while (loop1 < HEIGHT)
	{
		loop2 = 0;
		while (loop2 < WIDTH)
		{
			if (loop1 < HEIGHT / 2)
				data->game->addr[loop1 * WIDTH + loop2] = sky_color;
			else
				data->game->addr[loop1 * WIDTH + loop2] = surface_color;
			loop2++;
		}
		loop1++;
	}
}

static void	draw_col(t_data *data, int col)
{
	int	loop;
	int	color;
	int	tex_index;

	loop = data->ray->draw_start;
	while (loop < data->ray->draw_end)
	{
		data->ray->tex_y = (int)data->ray->tex_y_next & \
		(data->textures->size - 1);
		data->ray->tex_y_next += data->ray->unit_per_pix;
		tex_index = data->textures->size * data->ray->tex_y + \
		data->ray->tex_x;
		if (data->ray->raydir_x > 0 && data->ray->side != 1)
			color = data->textures->addr_s[tex_index];
		else if (data->ray->raydir_x < 0 && data->ray->side != 1)
			color = data->textures->addr_n[tex_index];
		else if ((data->ray->raydir_x <= 2 && data->ray->raydir_y >= 0)
			&& data->ray->side == 1)
			color = data->textures->addr_e[tex_index];
		else
			color = data->textures->addr_w[tex_index];
		data->game->addr[loop * WIDTH + col] = color;
		loop++;
	}
}

int	draw_textures(t_data *data)
{
	int	col;

	mlx_clear_window(data->game->mlx, data->game->win);
	sky_and_surface(data);
	col = -1;
	while (++col < WIDTH)
	{
		var_set(data, col);
		calculate_ray_piece(data);
		side_hit(data);
		calculate_side_distance(data);
		set_texture_starting_pixel(data);
		draw_col(data, col);
	}
	mlx_put_image_to_window(data->game->mlx, data->game->win, data->game->img,
		0, 0);
	move_player(data);
	return (0);
}
