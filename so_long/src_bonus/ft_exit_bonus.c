/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:34:10 by lofiorin          #+#    #+#             */
/*   Updated: 2024/03/15 14:24:02 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	destroy_enemy(t_data *window)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (window->img.enemy[i])
			mlx_destroy_image(window->mlx, window->img.enemy[i]);
	free(window->enemy_pos);
	return (0);
}

static int	destroy_player(t_data *window)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (window->img.player[i])
			mlx_destroy_image(window->mlx, window->img.player[i]);
	return (0);
}

int	ft_clean_exit(t_data *window, int status)
{
	int	i;

	i = -1;
	while (++i < 2)
		if (window->img.exit[i])
			mlx_destroy_image(window->mlx, window->img.exit[i]);
	if (window->img.wall)
		mlx_destroy_image(window->mlx, window->img.wall);
	if (window->img.coll)
		mlx_destroy_image(window->mlx, window->img.coll);
	if (window->img.floor)
		mlx_destroy_image(window->mlx, window->img.floor);
	destroy_enemy(window);
	destroy_player(window);
	if (window->img.banner)
		mlx_destroy_image(window->mlx, window->img.banner);
	if (window->win)
		mlx_destroy_window(window->mlx, window->win);
	if (window->mlx)
		mlx_destroy_display(window->mlx);
	if (window->map)
		ft_free_map(window->map);
	free(window->mlx);
	exit (status);
}
