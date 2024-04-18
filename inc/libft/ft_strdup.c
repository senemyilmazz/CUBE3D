/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <acan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:50:19 by acan              #+#    #+#             */
/*   Updated: 2024/02/20 15:38:58 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	count;
	size_t	size;

	count = 0;
	size = ft_strlen(s1);
	dst = malloc((size + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (count < size)
	{
		dst[count] = s1[count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
