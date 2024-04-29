/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_to_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:37:50 by senyilma          #+#    #+#             */
/*   Updated: 2024/04/29 19:46:27 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	set_viewdir(t_data *data, char dir)
{
	data->view->dir_x = 0;
	data->view->dir_y = 0;
	data->view->plane_x = 0;
	data->view->plane_y = 0;
	if (dir == 'N')
	{
		data->view->dir_y = -1;
		data->view->plane_x = 0.66;
	}
	else if (dir == 'S')
	{
		data->view->dir_y = 1;
		data->view->plane_x = -0.66;
	}
	else if (dir == 'W')
	{
		data->view->dir_x = -1;
		data->view->plane_y = -0.66;
	}
	else if (dir == 'E')
	{
		data->view->dir_x = 1;
		data->view->plane_y = 0.66;
	}
}
