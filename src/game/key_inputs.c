/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <acan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:41:48 by acan              #+#    #+#             */
/*   Updated: 2024/05/04 00:41:11 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	exit_game(t_data *data)
{
	mlx_destroy_window(data->game->mlx, data->game->win);
	exit(0);
}

int	key_press(int key, t_data *data)
{
	if (key == 13)
		data->keys->w = 1;
	if (key == 1)
		data->keys->s = 1;
	if (key == 0)
		data->keys->a = 1;
	if (key == 2)
		data->keys->d = 1;
	if (key == 123)
		data->keys->left = 1;
	if (key == 124)
		data->keys->right = 1;
	if (key == 53)
		exit_game(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == 13)
		data->keys->w = 0;
	if (key == 1)
		data->keys->s = 0;
	if (key == 0)
		data->keys->a = 0;
	if (key == 2)
		data->keys->d = 0;
	if (key == 123)
		data->keys->left = 0;
	if (key == 124)
		data->keys->right = 0;
	return (0);
}
