/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:40:31 by acan              #+#    #+#             */
/*   Updated: 2024/04/18 19:14:43 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

char	**double_strjoin(char **oldlist, char *str)
{
	char	**newlist;
	size_t	size;

	size = 0;
	while (oldlist && oldlist[size])
		size++;
	newlist = malloc(sizeof(char *) * (size + 2));
	size = 0;
	while (oldlist && oldlist[size])
	{
		newlist[size] = oldlist[size];
		size++;
	}
	newlist[size] = str;
	newlist[++size] = 0;
	free (oldlist);
	return (newlist);
}

int	own_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	double_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
