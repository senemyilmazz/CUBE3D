/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:38:25 by acan              #+#    #+#             */
/*   Updated: 2024/05/10 15:55:57 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	open_check(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		printerror("File not found or no read permission.");
	close(fd);
}

void	extension_check(char *file, char *extension)
{
	int	i;
	int	j;

	i = ft_strlen(file) - 4;
	j = 0;
	while (file[i] && extension[j])
	{
		if (file[i] != extension[j])
			printerror(ft_strjoin("Extension must be ", extension));
		i++;
		j++;
	}
}

void	hidden_file_check(char *file)
{
	int	i;

	if (file[0] == '.' && file[1] != '/')
		printerror("File is hidden.");
	i = 0;
	while (file[i])
	{
		if (file[i] == '/')
		{
			if (file[i + 1])
			{
				if (file[i + 1] == '.')
					printerror("File is hidden.");
			}
			else
				printerror("Is a folder.");
		}
		i++;
	}
}

void	check_file_path(char *file, char *extension)
{
	open_check(file);
	hidden_file_check(file);
	extension_check(file, extension);
}
