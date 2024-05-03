/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <acan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:22:36 by acan              #+#    #+#             */
/*   Updated: 2024/05/04 00:40:18 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	move_forward(t_data *data)
{
	if (data->map->map[(int)(data->player->pos_y + data->view->dir_y
			* data->game->move_speed)][(int)(data->player->pos_x)] == '0'
		|| data->map->map[(int)(data->player->pos_y + data->view->dir_y
			* data->game->move_speed)][(int)(data->player->pos_x)]
			== data->player->player_dir)
		data->player->pos_y += data->view->dir_y * data->game->move_speed;
	if (data->map->map[(int)data->player->pos_y][(int)(data->player->pos_x
		+ data->view->dir_x * data->game->move_speed)] == '0'
		|| data->map->map[(int)data->player->pos_y][(int)(data->player->pos_x
			+ data->view->dir_x
			* data->game->move_speed)] == data->player->player_dir)
		data->player->pos_x += data->view->dir_x * data->game->move_speed;
}

static void	move_backward(t_data *data)
{
	if (data->map->map[(int)(data->player->pos_y - data->view->dir_y
			* data->game->move_speed)][(int)(data->player->pos_x)] == '0'
		|| data->map->map[(int)(data->player->pos_y - data->view->dir_y
		* data->game->move_speed)][(int)(data->player->pos_x)]
		== data->player->player_dir)
		data->player->pos_y -= data->view->dir_y * data->game->move_speed;
	if (data->map->map[(int)data->player->pos_y][(int)(data->player->pos_x
		- data->view->dir_x * data->game->move_speed)] == '0'
		|| data->map->map[(int)data->player->pos_y][(int)(data->player->pos_x
			- data->view->dir_x
			* data->game->move_speed)] == data->player->player_dir)
		data->player->pos_x -= data->view->dir_x * data->game->move_speed;
}

static void	move_left(t_data *data)
{
	if (data->map->map[(int)(data->player->pos_y)][(int)(data->player->pos_x
			- data->view->plane_x * data->game->move_speed)] == '0'
		|| data->map->map[(int)(data->player->pos_y)][(int)(data->player->pos_x
			- data->view->plane_x
			* data->game->move_speed)] == data->player->player_dir)
		data->player->pos_x -= data->view->plane_x * data->game->move_speed;
	if (data->map->map[(int)(data->player->pos_y - data->view->plane_y
			* data->game->move_speed)][(int)(data->player->pos_x)] == '0'
		|| data->map->map[(int)(data->player->pos_y - data->view->plane_y
			* data->game->move_speed)][(int)(data->player->pos_x)]
			== data->player->player_dir)
		data->player->pos_y -= data->view->plane_y * data->game->move_speed;
}

static void	move_right(t_data *data)
{
	if (data->map->map[(int)(data->player->pos_y)][(int)(data->player->pos_x
			+ data->view->plane_x * data->game->move_speed)] == '0'
		|| data->map->map[(int)(data->player->pos_y)][(int)(data->player->pos_x
			+ data->view->plane_x
			* data->game->move_speed)] == data->player->player_dir)
		data->player->pos_x += data->view->plane_x * data->game->move_speed;
	if (data->map->map[(int)(data->player->pos_y + data->view->plane_y
			* data->game->move_speed)][(int)(data->player->pos_x)] == '0'
		|| data->map->map[(int)(data->player->pos_y + data->view->plane_y
			* data->game->move_speed)][(int)(data->player->pos_x)]
			== data->player->player_dir)
		data->player->pos_y += data->view->plane_y * data->game->move_speed;
}

void	move_player(t_data *data)
{
	if (data->keys->w)
		move_forward(data);
	if (data->keys->s)
		move_backward(data);
	if (data->keys->a)
		move_left(data);
	if (data->keys->d)
		move_right(data);
	if (data->keys->right)
		cam_right(data);
	if (data->keys->left)
		cam_left(data);
}
