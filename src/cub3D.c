/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <acan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:37:39 by acan              #+#    #+#             */
/*   Updated: 2024/05/04 00:41:27 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	init_data(t_data *data)
{
	data->file = NULL;
	data->map = malloc(sizeof(t_map));
	data->textures = malloc(sizeof(t_texture));
	data->view = malloc(sizeof(t_view));
	data->ray = malloc(sizeof(t_ray));
	data->keys = malloc(sizeof(t_keys));
	data->player = malloc(sizeof(t_player));
	data->game = malloc(sizeof(t_game));
	data->map->map = NULL;
	data->textures->no = NULL;
	data->textures->so = NULL;
	data->textures->we = NULL;
	data->textures->ea = NULL;
	data->textures->f = NULL;
	data->textures->c = NULL;
	data->player->pos_x = -1;
	data->player->pos_y = -1;
	data->game->mlx = NULL;
	data->game->win = NULL;
	data->game->img = NULL;
	data->game->addr = NULL;
	data->game->x = 0;
	data->keys->w = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		printerror("Argument error");
	init_data(&data);
	check_file(av[1], &data);
	game(&data);
	return (0);
}
