/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:37:47 by acan              #+#    #+#             */
/*   Updated: 2024/04/29 20:10:03 by senyilma         ###   ########.fr       */
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

int	draw_content(t_data *data)
{
	int	col;

	mlx_clear_window(data->game->mlx, data->game->win);
	sky_and_surface(data);
	col = 0;
	while (col < WIDTH)
	{
		var_set(data, col);
		col++;
	}
	mlx_put_image_to_window(data->game->mlx, data->game->win, data->game->img,
		0, 0);
	return (0);
}
