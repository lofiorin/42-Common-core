/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:58:12 by lofiorin          #+#    #+#             */
/*   Updated: 2024/01/18 12:47:59 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*buffer_setter(char *buffer, int fd)
{
	char	*buffer_tmp;
	int		read_chr;

	buffer_tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer_tmp)
		return (NULL);
	read_chr = BUFFER_SIZE;
	while (!ft_strchr(buffer_tmp, '\n') && read_chr != 0)
	{
		read_chr = read(fd, buffer_tmp, BUFFER_SIZE);
		if (read_chr == -1)
		{
			free(buffer_tmp);
			return (NULL);
		}
		buffer = ft_strnjoin(buffer, buffer_tmp, read_chr);
		if (ft_strlen(buffer) == 0)
		{
			free(buffer);
			free(buffer_tmp);
			return (NULL);
		}
	}
	free(buffer_tmp);
	return (buffer);
}

static char	*next_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*buffer_update(char *buffer)
{
	char	*buffer_tmp;
	int		i;

	i = 0;
	while (buffer && buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer || !buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	buffer_tmp = ft_strnjoin(NULL, buffer + i + !!buffer[i],
			ft_strlen(buffer) - i + !buffer[i] - 1);
	free (buffer);
	return (buffer_tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*fd_buffer[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_buffer[fd] = buffer_setter(fd_buffer[fd], fd);
	if (!fd_buffer[fd])
		return (NULL);
	line = next_line(fd_buffer[fd]);
	fd_buffer[fd] = buffer_update(fd_buffer[fd]);
	return (line);
}
/* 
int	main(void)
{
	int fd = open("empty", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	for(int i = 0; i < 2; i++){
		free(str);
		str = get_next_line(fd);
		printf("%s", str);
	}
	free(str);
	return (0);
} */
