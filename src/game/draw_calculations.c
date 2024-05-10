/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:59:16 by senyilma          #+#    #+#             */
/*   Updated: 2024/05/10 14:19:19 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	var_set(t_data *data, int width)
{
	data->ray->camera_x = 2 * width / (double)WIDTH - 1;
	data->ray->raydir_x = data->view->dir_x + (data->view->plane_x)
		* data->ray->camera_x;
	data->ray->raydir_y = data->view->dir_y + (data->view->plane_y)
		* data->ray->camera_x;
	data->ray->pos_x = (int)data->player->pos_x;
	data->ray->pos_y = (int)data->player->pos_y;
	data->ray->deltadist_x = fabs(1 / data->ray->raydir_x);
	data->ray->deltadist_y = fabs(1 / data->ray->raydir_y);
}

void	calculate_ray_piece(t_data *data)
{
	if (data->ray->raydir_x < 0)
	{
		data->ray->step_x = -1;
		data->ray->sidedist_x = (data->player->pos_x - data->ray->pos_x)
			* data->ray->deltadist_x;
	}
	else
	{
		data->ray->step_x = 1;
		data->ray->sidedist_x = (data->ray->pos_x + 1.0 - data->player->pos_x)
			* data->ray->deltadist_x;
	}
	if (data->ray->raydir_y < 0)
	{
		data->ray->step_y = -1;
		data->ray->sidedist_y = (data->player->pos_y - data->ray->pos_y)
			* data->ray->deltadist_y;
	}
	else
	{
		data->ray->step_y = 1;
		data->ray->sidedist_y = (data->ray->pos_y + 1.0 - data->player->pos_y)
			* data->ray->deltadist_y;
	}
}

void	side_hit(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->ray->sidedist_x < data->ray->sidedist_y)
		{
			data->ray->sidedist_x += data->ray->deltadist_x;
			data->ray->pos_x += data->ray->step_x;
			data->ray->side = 0;
		}
		else
		{
			data->ray->sidedist_y += data->ray->deltadist_y;
			data->ray->pos_y += data->ray->step_y;
			data->ray->side = 1;
		}
		if (data->map[data->ray->pos_y][data->ray->pos_x] == '1')
			hit = 1;
	}
}

void	calculate_side_distance(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->plane_wall_dist = data->ray->sidedist_x
			- data->ray->deltadist_x;
	else
		data->ray->plane_wall_dist = data->ray->sidedist_y
			- data->ray->deltadist_y;
	data->ray->draw_height = (int)(HEIGHT / data->ray->plane_wall_dist);
	data->ray->draw_start = -data->ray->draw_height / 2 + HEIGHT / 2;
	if (data->ray->draw_start < 0)
		data->ray->draw_start = 0;
	data->ray->draw_end = data->ray->draw_height / 2 + HEIGHT / 2;
	if (data->ray->draw_end >= HEIGHT)
		data->ray->draw_end = HEIGHT - 1;
}

void	set_texture_starting_pixel(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->hit_x = data->player->pos_y + data->ray->plane_wall_dist
			* data->ray->raydir_y;
	else
		data->ray->hit_x = data->player->pos_x + data->ray->plane_wall_dist
			* data->ray->raydir_x;
	data->ray->hit_x -= floor(data->ray->hit_x);
	data->ray->tex_x = (int)(data->ray->hit_x * 64);
	data->ray->unit_per_pix = 1.0 * 64 / data->ray->draw_height;
	data->ray->tex_y_next = (data->ray->draw_start - HEIGHT / 2
			+ data->ray->draw_height / 2) * data->ray->unit_per_pix;
}
