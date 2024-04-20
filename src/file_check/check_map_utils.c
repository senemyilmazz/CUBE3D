/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:40:49 by senyilma          #+#    #+#             */
/*   Updated: 2024/04/20 15:41:00 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	find_max_len(char **content)
{
	int		max_len;
	int		len;

	max_len = 0;
	while (*content)
	{
		len = ft_strlen(*content);
		if (len > max_len)
			max_len = len;
		content++;
	}
	return (max_len);
}

char	*add_null(char *line, int max_len)
{
	int		i;
	char	*spaces_to_add;

	spaces_to_add = NULL;
	i = ft_strlen(line) - 1;
	while (++i < max_len)
		spaces_to_add = own_strjoin(spaces_to_add, " ");
	line = own_strjoin(line, spaces_to_add);
	free_and_set_null(spaces_to_add);
	return (line);
}
