/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:38:05 by lofiorin          #+#    #+#             */
/*   Updated: 2024/03/15 14:33:00 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**map_copy(char **map)
{
	char	**map_cpy;
	int		i;

	i = 0;
	map_cpy = malloc (sizeof(char *) * (count_map_lines(map) + 1));
	if (!map_cpy)
		return (NULL);
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
			return (ft_free_map(map_cpy), NULL);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

static void	flood_fill(int x, int y, t_parsing	*control)
{
	if (control->map[y][x] == '1' || control->map[y][x] == 'E'
		|| control->map[y][x] == '2')
	{
		if (control->map[y][x] == 'E')
			control->exit_found = 1;
		return ;
	}
	control->map[y][x] = '2';
	flood_fill(x + 1, y, control);
	flood_fill(x - 1, y, control);
	flood_fill(x, y + 1, control);
	flood_fill(x, y - 1, control);
}

static int	flood_fill_check(t_parsing *control)
{
	int	i;
	int	j;

	j = -1;
	flood_fill(control->player_pos.x, control->player_pos.y, control);
	if (control->exit_found != 1)
		return (ft_printf("UNABLE TO REACH THE EXIT\n"), 0);
	while (control->map[++j])
	{
		i = -1;
		while (control->map[j][++i])
			if (control->map[j][i] == 'C')
				return (ft_printf("UNABLE TO REACH ALL COLLECTABLES\n"), 0);
	}
	return (1);
}

int	ft_parsing(t_data *window)
{
	t_parsing	control;

	control = (t_parsing){0};
	control.map = map_copy(window->map);
	if (!control.map)
		return (0);
	if (!ft_control_shape(control.map))
		return (ft_free_map(control.map), 0);
	if (!ft_control_walls(control.map))
		return (ft_free_map(control.map), 0);
	if (!ft_final_control(&control))
		return (ft_free_map(control.map), 0);
	if (!flood_fill_check(&control))
		return (ft_free_map(control.map), 0);
	return (ft_free_map(control.map), 1);
}
