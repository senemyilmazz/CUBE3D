/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <acan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:37:47 by acan              #+#    #+#             */
/*   Updated: 2024/05/03 23:43:31 by acan             ###   ########.fr       */
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

void	set_image_values(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->wall_pos_x = data->player->pos_y + data->ray->perpwalldist
			* data->ray->raydir_y;
	else
		data->ray->wall_pos_x = data->player->pos_x + data->ray->perpwalldist
			* data->ray->raydir_x;
	data->ray->wall_pos_x -= floor(data->ray->wall_pos_x);
	data->ray->tex_x = (int)(data->ray->wall_pos_x * 64);
	if (data->ray->side == 0 && data->ray->raydir_x > 0)
		data->ray->tex_x = 64 - data->ray->tex_x - 1;
	if (data->ray->side == 1 && data->ray->raydir_y < 0)
		data->ray->tex_x = 64 - data->ray->tex_x - 1;
	data->ray->pixel_cal = 1.0 * 64 / data->ray->lineheight;
	data->ray->pixel_num = (data->ray->drawstart - HEIGHT / 2
			+ data->ray->lineheight / 2) * data->ray->pixel_cal;
}

void	draw_image(t_data *data, int col)
{
	int	loop;
	int	color;

	loop = data->ray->drawstart;
	while (loop < data->ray->drawend)
	{
		data->ray->tex_y = (int)data->ray->pixel_num & (data->game->x - 1);
		data->ray->pixel_num += data->ray->pixel_cal;
		if (data->ray->raydir_x > 0 && data->ray->side != 1)
			color = data->textures->addr_s[data->game->x * data->ray->tex_y
				+ data->ray->tex_x];
		else if (data->ray->raydir_x < 0 && data->ray->side != 1)
			color = data->textures->addr_n[data->game->x * data->ray->tex_y
				+ data->ray->tex_x];
		else if ((data->ray->raydir_x <= 2 && data->ray->raydir_y >= 0)
			&& data->ray->side == 1)
			color = data->textures->addr_e[data->game->x * data->ray->tex_y
				+ data->ray->tex_x];
		else
			color = data->textures->addr_w[data->game->x * data->ray->tex_y
				+ data->ray->tex_x];
		data->game->addr[loop * WIDTH + col] = color;
		loop++;
	}
}

int	draw_content(t_data *data)
{
	int	col;

	mlx_clear_window(data->game->mlx, data->game->win);
	sky_and_surface(data);
	col = 0;
	while (col < WIDTH)
	{
		var_set(data, col);
		wall_control(data);
		wall_hit(data);
		calculate_distance(data);
		set_image_values(data);
		draw_image(data, col);
		col++;
	}
	mlx_put_image_to_window(data->game->mlx, data->game->win, data->game->img,
		0, 0);
	move_player(data);
	return (0);
}