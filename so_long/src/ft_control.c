/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:49:08 by lofiorin          #+#    #+#             */
/*   Updated: 2024/03/15 14:39:14 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_lines(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	return (i);
}

int	ft_control_shape(char **map)
{
	int		i;
	size_t	a;

	i = 0;
	a = ft_strlen(map[i]);
	if (a < 3)
		return (ft_printf("MAP TOO SMALL\n"), 0);
	if (a > 60)
		return (ft_printf("MAP TOO BIG\n"), 0);
	while (map[++i])
	{
		if (ft_strlen(map[i]) != a)
			return (ft_printf ("MAP MUST HAVE A REGULAR SHAPE\n"), 0);
	}
	return (1);
}

int	ft_control_walls(char **map)
{
	int		i;
	size_t	j;
	int		i_last;

	j = -1;
	i_last = count_map_lines(map) - 1;
	while (++j < ft_strlen(map[0]))
		if (map[0][j] != '1' || map[i_last][j] != '1')
			return (ft_printf ("MAP MUST BE SURROUNDED BY WALLS\n"), 0);
	i = -1;
	while (++i < i_last)
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (ft_printf ("MAP MUST BE SURROUNDED BY WALLS\n"), 0);
	if (i_last > 30)
		return (ft_printf("MAP TOO BIG\n"), 0);
	return (1);
}

static void	ft_control_counter(t_parsing *control)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count_map_lines(control->map) - 1)
	{
		j = -1;
		while (control->map[i][++j])
		{
			if (control->map[i][j] == 'P')
			{
				control->player++;
				control->player_pos.x = j;
				control->player_pos.y = i;
			}
			else if (control->map[i][j] == 'E')
				control->exit++;
			else if (control->map[i][j] == 'C')
				control->collectable++;
			else if (control->map[i][j] != '0' && control->map[i][j] != '1')
				control->wit++;
		}
	}
}

int	ft_final_control(t_parsing *control)
{
	ft_control_counter(control);
	if (control->player != 1)
		return (ft_printf ("PLAYER MUST HAVE 1 START POSITION\n"), 0);
	if (control->exit != 1)
		return (ft_printf ("MAP MUST HAVE 1 EXIT\n"), 0);
	if (control->collectable < 1)
		return (ft_printf ("MAP MUST HAVE AT LEAST 1 COLLECTABLE\n"), 0);
	if (control->wit)
		return (ft_printf ("INVALID ELEMENT ON MAP\n"), 0);
	return (1);
}
