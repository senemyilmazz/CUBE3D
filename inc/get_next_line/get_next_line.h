/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <acan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:15:52 by acan              #+#    #+#             */
/*   Updated: 2024/02/20 15:37:06 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int		strlen_int(char *s);
char	*buf_to_text(char *text, char *buf);
int		hasnlornull(char *s);
char	*find_line(int fd, char *text);
char	*seperate_line(char	*text);
char	*cut_line(char *text);
char	*get_next_line(int fd);
char	*ft_calloc_gnl(int count);
#endif