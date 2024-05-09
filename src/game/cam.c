/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:25:36 by acan              #+#    #+#             */
/*   Updated: 2024/05/09 17:57:52 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	cam_left(t_data *data)
{
	data->view->old_dir_x = data->view->dir_x;
	data->view->dir_x = data->view->dir_x * cos(-data->game->rot_speed)
		- data->view->dir_y * sin(-data->game->rot_speed);
	data->view->dir_y = data->view->dir_x * sin(-data->game->rot_speed)
		+ data->view->dir_y * cos(-data->game->rot_speed);
	data->view->old_plane_x = data->view->plane_x;
	data->view->plane_x = data->view->plane_x * cos(-data->game->rot_speed)
		- data->view->plane_y * sin(-data->game->rot_speed);
	data->view->plane_y = data->view->old_plane_x * sin(-data->game->rot_speed)
		+ data->view->plane_y * cos(-data->game->rot_speed);
}

void	cam_right(t_data *data)
{
	data->view->old_dir_x = data->view->dir_x;
	data->view->dir_x = data->view->dir_x * cos(data->game->rot_speed)
		- data->view->dir_y * sin(data->game->rot_speed);
	data->view->dir_y = data->view->old_dir_x * sin(data->game->rot_speed)
		+ data->view->dir_y * cos(data->game->rot_speed);
	data->view->old_plane_x = data->view->plane_x;
	data->view->plane_x = data->view->plane_x * cos(data->game->rot_speed)
		- data->view->plane_y * sin(data->game->rot_speed);
	data->view->plane_y = data->view->old_plane_x * sin(data->game->rot_speed)
		+ data->view->plane_y * cos(data->game->rot_speed);
}
