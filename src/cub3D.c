/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <acan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:37:39 by acan              #+#    #+#             */
/*   Updated: 2024/04/25 19:33:57 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	init_data(t_data *data)
{
	data->file = NULL;
	data->map = malloc(sizeof(t_map));
	data->map->map = NULL;
	data->textures = malloc(sizeof(t_texture));
	data->textures->no = NULL;
	data->textures->so = NULL;
	data->textures->we = NULL;
	data->textures->ea = NULL;
	data->textures->f = NULL;
	data->textures->c = NULL;
	data->player = malloc(sizeof(t_player));
	data->player->pos_x = -1;
	data->player->pos_y = -1;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		printerror("Argument error");
	init_data(&data);
	check_file(av[1], &data);
	// system("leaks cub3D");
	return (0);
}

// void __attribute__((destructor)) destruct(void)
//{
//    system("leaks cub3D");
//}