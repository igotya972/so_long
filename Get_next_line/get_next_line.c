/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:39:19 by dferjul           #+#    #+#             */
/*   Updated: 2023/06/29 23:51:32 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *buf, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(buf, line);
	free(buf);
	return (tmp);
}

char	*ft_first_line(char *buf)
{
	int		i;
	char	*dest;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	dest = ft_calloc(i + 2, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		dest[i] = '\n';
		dest[i + 1] = '\0';
	}
	else
		dest[i] = '\0';
	return (dest);
}

char	*ft_second_line(char *buf)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(buf) - (i)));
	if (!dest)
		return (NULL);
	i++;
	j = 0;
	dest = ft_strcpy(&dest[j], &buf[i]);
	free(buf);
	return (dest);
}

char	*read_file(int fd, char *result)
{
	char	*tmp;
	int		byte_read;

	byte_read = 1;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	if (!result)
		result = ft_calloc(1, 1);
	while (byte_read > 0)
	{
		byte_read = read(fd, tmp, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(tmp);
			free(result);
			return (NULL);
		}
		tmp[byte_read] = '\0';
		result = ft_join(result, tmp);
		if (ft_strchr(result, '\n'))
			break ;
	}
	free(tmp);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buf)
		{
			free(buf);
			buf = 0;
		}
		return (NULL);
	}
	buf = read_file(fd, buf);
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	line = ft_first_line(buf);
	buf = ft_second_line(buf);
	return (line);
}
