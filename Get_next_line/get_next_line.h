/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:25:15 by dferjul           #+#    #+#             */
/*   Updated: 2023/03/11 02:45:12 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*read_line(int fd, char *result);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char *buf);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_second_line(char *buf);
char	*ft_first_line(char *buf);
char	*ft_join(char *buf, char *line);

#endif