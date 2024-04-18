/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:15:54 by acan              #+#    #+#             */
/*   Updated: 2023/08/10 12:59:06 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_line(int fd, char *text)
{
	int		rdcount;
	char	*buf;

	rdcount = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (rdcount != 0 && !hasnlornull(text))
	{
		rdcount = read(fd, buf, BUFFER_SIZE);
		if (rdcount < 0)
		{
			free(buf);
			free(text);
			return (NULL);
		}
		buf[rdcount] = '\0';
		text = buf_to_text(text, buf);
	}
	free(buf);
	return (text);
}

char	*seperate_line(char *text)
{
	int		i;
	char	*ret;
	int		j;

	i = 0;
	if (!*text)
		return (NULL);
	while (text[i] != '\n' && text[i])
		i++;
	if (text[i] == '\n')
		i++;
	ret = (char *)malloc(i + 1);
	j = -1;
	while (++j < i)
		ret[j] = text[j];
	ret[j] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(text);
		return (NULL);
	}
	text = find_line(fd, text);
	if (!text)
		return (NULL);
	line = seperate_line(text);
	text = cut_line(text);
	return (line);
}
