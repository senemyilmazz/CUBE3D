/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:59:16 by senyilma          #+#    #+#             */
/*   Updated: 2024/04/29 20:07:21 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	var_set(t_data *data, int width)
{
	data->ray->camera_x = 2 * width / (double)WIDTH - 1;
	data->ray->raydir_x = data->view->dir_x
		+ data->view->plane_x * data->ray->camera_x;
	data->ray->raydir_y = data->view->dir_y
		+ data->view->plane_y * data->ray->camera_x;
	data->ray->pos_x = (int)data->player->pos_x;
	data->ray->pos_y = (int)data->player->pos_y;
	data->ray->deltadist_x = fabs(1 / data->ray->raydir_x);
	data->ray->deltadist_y = fabs(1 / data->ray->raydir_y);
	data->ray->hit = 0;
}
