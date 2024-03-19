/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:31:06 by lofiorin          #+#    #+#             */
/*   Updated: 2024/03/15 14:23:39 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_exit_x(t_data *data)
{
	ft_clean_exit(data, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	prova;

	if (argc != 2)
	{
		ft_printf("Type ONE map name after the program name");
		return (1);
	}
	prova = (t_data){0};
	if (ft_map_gen(&prova, argv[1]))
		return (!ft_clean_exit(&prova, 1));
	if (!ft_parsing(&prova))
		return (!ft_clean_exit(&prova, 1));
	prova.mlx = mlx_init();
	if (!prova.mlx)
		return (!ft_clean_exit(&prova, 1));
	prova.win = mlx_new_window(prova.mlx,
			ft_strlen(prova.map[0]) * IMG_WIDTH,
			count_map_lines(prova.map) * IMG_HEIGHT,
			"Honey I'm coming");
	ft_render(&prova);
	if (!enemy_init(&prova))
		return (!ft_clean_exit(&prova, 1));
	mlx_hook(prova.win, 17, 0, ft_exit_x, &prova);
	mlx_hook(prova.win, 2, 1L << 0, ft_movement, &prova);
	mlx_loop(prova.mlx);
}
