/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <acan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:15:49 by acan              #+#    #+#             */
/*   Updated: 2024/02/20 18:16:18 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buf_to_text(char *text, char *buf)
{
	char	*ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!text)
		text = (char *)ft_calloc_gnl(1);
	ret = malloc((strlen_int(text) + strlen_int(buf) + 1));
	if (!ret)
		return (NULL);
	while (text[i])
	{
		ret[i] = text[i];
		i++;
	}
	while (buf[j])
		ret[i++] = buf[j++];
	ret[i] = '\0';
	free(text);
	return (ret);
}

int	strlen_int(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	hasnlornull(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*cut_line(char *text)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (text[i] != '\n' && text[i])
		i++;
	if (text[i] == '\0')
	{
		free(text);
		return (0);
	}
	i++;
	j = strlen_int(text);
	ret = (char *)ft_calloc_gnl(j - i + 1);
	if (!ret)
		return (NULL);
	j = 0;
	while (text[i])
		ret[j++] = text[i++];
	ret[j] = '\0';
	free(text);
	return (ret);
}

char	*ft_calloc_gnl(int count)
{
	char	*a;
	int		i;

	i = 0;
	a = malloc(count);
	if (!a)
		return (NULL);
	while (i < count)
		a[i++] = '\0';
	return (a);
}
