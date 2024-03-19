/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movement_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:14:35 by lofiorin          #+#    #+#             */
/*   Updated: 2024/03/15 14:24:11 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_put_enemy(t_data *window, int x, int y, int i)
{
	int	new_x;
	int	new_y;

	new_x = window->enemy_pos[i].x;
	new_y = window->enemy_pos[i].y;
	if (y < new_y)
		put_img(window, window->img.enemy[0], new_x, new_y);
	else if (y > new_y)
		put_img(window, window->img.enemy[1], new_x, new_y);
	else if (x > new_x)
		put_img(window, window->img.enemy[2], new_x, new_y);
	else if (x < new_x)
		put_img(window, window->img.enemy[3], new_x, new_y);
	else
		put_img(window, window->img.enemy[0], new_x, new_y);
	return (0);
}

int	enemy_init(t_data *window)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = -1;
	window->enemy_pos = malloc(sizeof(t_coord) * (window->enemies));
	if (!window->enemy_pos)
		return (0);
	while (window->map[++y])
	{
		x = -1;
		while (window->map[y][++x])
		{
			if (window->map[y][x] == 'G')
			{
				window->enemy_pos[i].x = x;
				window->enemy_pos[i].y = y;
				i++;
			}
		}
	}
	return (1);
}

static void	move_calculator(t_data *window, int x, int y, int i)
{
	int	rx;
	int	ry;

	rx = window->player_pos.x - x;
	ry = window->player_pos.y - y;
	if (rx < 0 && ft_move_check(window, x - 1, y, 'G'))
		window->enemy_pos[i].x -= 1;
	else
		rx = 1;
	if (ry < 0 && ft_move_check(window, x, y - 1, 'G')
		&& (x == window->enemy_pos[i].x && y == window->enemy_pos[i].y))
		window->enemy_pos[i].y -= 1;
	else
		ry = 1;
	if (rx > 0 && ft_move_check(window, x + 1, y, 'G')
		&& (x == window->enemy_pos[i].x && y == window->enemy_pos[i].y)
		&& (x != window->player_pos.x))
		window->enemy_pos[i].x += 1;
	else if (ry > 0 && ft_move_check(window, x, y + 1, 'G')
		&& (x == window->enemy_pos[i].x && y == window->enemy_pos[i].y))
		window->enemy_pos[i].y += 1;
}

int	ft_enemy_movement(t_data *window)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	while (++i < window->enemies)
	{
		x = window->enemy_pos[i].x;
		y = window->enemy_pos[i].y;
		window->map[y][x] = '0';
		ft_select_image(window, '0', x, y);
		move_calculator(window, x, y, i);
		window->map[window->enemy_pos[i].y][window->enemy_pos[i].x] = 'G';
		ft_put_enemy(window, x, y, i);
	}
	return (0);
}
