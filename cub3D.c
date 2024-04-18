/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:37:39 by acan              #+#    #+#             */
/*   Updated: 2024/04/18 03:45:11 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void    init_data(t_data *data)
{
    data->file = NULL;
    data->map = NULL;
    data->textures = malloc(sizeof(t_texture));
    data->textures->no = NULL;
    data->textures->so = NULL;
    data->textures->we = NULL;
    data->textures->ea = NULL;
    data->textures->f = NULL;
    data->textures->c = NULL;
}

int    main(int ac, char **av)
{
    t_data  data;

    if (ac != 2)
        printerror("Argument error");
    file_check(av[1]);
    init_data(&data);
    read_file(av[1], &data);

    
    system("leaks cub3D");
    return (0);
}

//void __attribute__((destructor)) destruct(void)
//{
//    system("leaks cub3D");
//}