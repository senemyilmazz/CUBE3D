/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <acan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:37:47 by acan              #+#    #+#             */
/*   Updated: 2024/04/29 18:41:12 by acan             ###   ########.fr       */
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
	mlx_clear_window(data->game->mlx, data->game->win);
	sky_and_surface(data);
	mlx_put_image_to_window(data->game->mlx, data->game->win, data->game->img,
		0, 0);
	return (0);
}
