/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:11:37 by acan              #+#    #+#             */
/*   Updated: 2023/07/12 15:18:16 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		tmp[i++] = *s1++;
	while (*s2 != '\0')
		tmp[i++] = *s2++;
	tmp[i] = '\0';
	return (tmp);
}
