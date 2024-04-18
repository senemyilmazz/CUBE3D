/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:40:31 by acan              #+#    #+#             */
/*   Updated: 2024/04/18 04:13:06 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    printerror(char *error)
{
    write(2, error, ft_strlen(error));
    write(2, "\n", 1);
    exit (1);
}

char    **double_strjoin(char **oldlist, char *str)
{
    char    **newlist;
    size_t     size;

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

int own_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    if (!s1 || !s2)
        return (1);
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int atoi_for_rgb(const char *str)
{
    size_t	count;
	int		result;
    char    *code;

	count = 0;
	result = 0;
    code = ft_strtrim(str, " ");
	if (code[count] == '-' || code[count] == '+')
	{
		if (code[count] == '-')
			printerror("Invalid RGB value.");
		count++;
	}
	while (code[count] >= '0' && code[count] <= '9')
	{
		result = (result * 10) + code[count] - '0';
        if (result > 255)
            printerror("Invalid RGB value.");
		count++;
	}
    if (code[count] != '\0')
        printerror("Invalid RGB value.");
    free(code);
	return (result);
}