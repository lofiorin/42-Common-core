/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_gen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:23:51 by lofiorin          #+#    #+#             */
/*   Updated: 2024/03/15 14:23:51 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	dir_check(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY | __O_DIRECTORY);
	if (fd < 0)
		return (0);
	return (close(fd), 1);
}

static int	rows_alloc(t_data *window, char *file_name)
{
	int		i;
	int		fd;
	int		row_count;
	char	char_check;
	void	*char_ptr;

	i = -1;
	row_count = 1;
	char_ptr = &char_check;
	if (dir_check(file_name))
		return (ft_printf("The map must be a file\n"), 0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Problems opening the file\n"), 0);
	while (read(fd, char_ptr, 1) > 0)
		if (char_check == '\n')
			row_count++;
	close(fd);
	window->map = malloc(sizeof(char *) * (row_count + 1));
	while (++i <= row_count)
		window->map[i] = NULL;
	return (row_count);
}

static int	ft_mini_map_gen(int fd, int row_count, t_data *window)
{
	char	*tmp;
	int		i;

	i = -1;
	while (++i < row_count)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (ft_strlen(tmp) > 1)
			window->map[i] = ft_strtrim(tmp, "\n");
		else
			window->map[i] = ft_strdup(tmp);
		if (!window->map[i])
			break ;
		free(tmp);
		tmp = NULL;
	}
	if (tmp)
		return (free(tmp), 0);
	return (1);
}

int	ft_map_gen(t_data *window, char *file_name)
{
	int		fd;
	int		row_count;
	int		name_len;

	name_len = ft_strlen(file_name);
	if (name_len < 4 || ft_strncmp(file_name + name_len - 4, ".ber", 4))
		return (ft_printf("Invalid file type\n"), 1);
	row_count = rows_alloc(window, file_name);
	if (!window->map)
		return (ft_printf("Invalid map allocation."), 1);
	fd = open(file_name, O_RDONLY);
	if (!ft_mini_map_gen(fd, row_count, window))
		return (close(fd), 1);
	return (close(fd), 0);
}
