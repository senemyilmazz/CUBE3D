/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:59:16 by senyilma          #+#    #+#             */
/*   Updated: 2024/04/30 18:57:06 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	var_set(t_data *data, int width)
{
	data->ray->camera_x = 2 * width / (double)WIDTH - 1;
	data->ray->raydir_x = data->view->dir_x + data->view->plane_x
		* data->ray->camera_x;
	data->ray->raydir_y = data->view->dir_y + data->view->plane_y
		* data->ray->camera_x;
	data->ray->pos_x = (int)data->player->pos_x;
	data->ray->pos_y = (int)data->player->pos_y;
	data->ray->deltadist_x = fabs(1 / data->ray->raydir_x);
	data->ray->deltadist_y = fabs(1 / data->ray->raydir_y);
	data->ray->hit = 0;
}

void	wall_control(t_data *data)
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
		data->ray->sidedist_y = (data->ray->pos_x + 1.0 - data->player->pos_x)
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

void	wall_hit(t_data *data)
{
	while (data->ray->hit == 0)
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
		if (data->map->map[data->ray->pos_x][data->ray->pos_y] == '1')
			data->ray->hit = 1;
	}
}

void	calculate_distance(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->perpwalldist = (data->ray->pos_x - data->player->pos_x + (1
					- data->ray->step_x) / 2) / data->ray->raydir_x;
	else
		data->ray->perpwalldist = (data->ray->pos_y - data->player->pos_y + (1
					- data->ray->step_y) / 2) / data->ray->raydir_y;
	data->ray->lineheight = (int)(HEIGHT / data->ray->perpwalldist);
	data->ray->drawstart = -data->ray->lineheight / 2 + HEIGHT / 2;
	if (data->ray->drawstart < 0)
		data->ray->drawstart = 0;
	data->ray->drawend = data->ray->lineheight / 2 + HEIGHT / 2;
	if (data->ray->drawend >= HEIGHT)
		data->ray->drawend = HEIGHT - 1;
}