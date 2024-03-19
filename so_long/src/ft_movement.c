/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:00:13 by lofiorin          #+#    #+#             */
/*   Updated: 2024/03/15 14:43:04 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_collectable_check(t_data *window)
{
	int	i;
	int	j;

	j = 0;
	window->collectable--;
	if (window->collectable == 0)
	{
		while (window->map[j])
		{
			i = 0;
			while (window->map[j][i])
			{
				if (window->map[j][i] == 'E')
				{
					put_img(window, window->img.exit[1], i, j);
					return ;
				}
				i++;
			}
			j++;
		}
	}
}

int	ft_move_check(t_data *window, int x, int y, char entity)
{
	if (entity == 'P')
	{
		if (window->map[y][x] == '1')
			return (0);
		if (window->map[y][x] == 'E' && window->collectable != 0)
			return (0);
		if ((window->map[y][x] == 'E' && window->collectable == 0))
			ft_clean_exit(window, 0);
		if (window->map[y][x] == 'C')
		{
			ft_collectable_check(window);
			window->map[y][x] = 0;
		}
	}
	return (1);
}

void	move_player_sprite(t_data *window, int key, int x, int y)
{
	ft_printf("moves: %d\n", window->moves);
	if (key == 'w' || key == U)
		put_img(window, window->img.player[3], x, y);
	else if (key == 'a' || key == L)
		put_img(window, window->img.player[1], x, y);
	else if (key == 'd' || key == R)
		put_img(window, window->img.player[0], x, y);
	else
		put_img(window, window->img.player[2], x, y);
}

int	ft_movement(int key, t_data *window)
{
	int	x;
	int	y;

	x = window->player_pos.x;
	y = window->player_pos.y;
	window->map[y][x] = '0';
	put_img(window, window->img.floor, x, y);
	window->moves++;
	if ((key == 'w' || key == U) && ft_move_check(window, x, y - 1, 'P'))
		y -= 1;
	else if ((key == 's' || key == D) && ft_move_check(window, x, y + 1, 'P'))
		y += 1;
	else if ((key == 'a' || key == L) && ft_move_check(window, x - 1, y, 'P'))
		x -= 1;
	else if ((key == 'd' || key == R) && ft_move_check(window, x + 1, y, 'P'))
		x += 1;
	move_player_sprite(window, key, x, y);
	window->map[y][x] = 'P';
	window->player_pos.x = x;
	window->player_pos.y = y;
	if (key == ESC)
		ft_clean_exit(window, 0);
	return (0);
}
