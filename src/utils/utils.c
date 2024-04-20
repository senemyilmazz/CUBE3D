/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:40:31 by acan              #+#    #+#             */
/*   Updated: 2024/04/20 15:37:35 by senyilma         ###   ########.fr       */
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
		free_and_set_null(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	free_and_set_null(char *str)
{
	if (!str)
		return ;
	free(str);
	str = NULL;
}

char	*own_strjoin(char *s1, char *s2)
{
	char	*s1s2;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	s1s2 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1s2)
	{
		return (NULL);
	}
	i = -1;
	while (++i < ft_strlen(s1))
		s1s2[i] = s1[i];
	j = -1;
	while (++j < ft_strlen(s2))
		s1s2[i + j] = s2[j];
	s1s2[i + j] = '\0';
	if (s1)
		free_and_set_null((char *)s1);
	return (s1s2);
}
