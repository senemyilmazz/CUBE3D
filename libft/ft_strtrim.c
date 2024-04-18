/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:21:41 by acan              #+#    #+#             */
/*   Updated: 2024/04/17 22:29:03 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*cuttedstring;
	int		i;
	int		endofs;

	i = 0;
	if (s != NULL)
	{
		while (s[i] && ft_strchr(set, s[i]))
			i++;
		endofs = ft_strlen(s) - 1;
		while (endofs > i && ft_strchr(set, s[endofs]))
			endofs--;
		if (endofs < i)
			return (ft_strdup(""));
		cuttedstring = ft_substr(s, i, endofs - i + 1);
		return (cuttedstring);
	}
	return (NULL);
}
