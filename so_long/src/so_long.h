/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:18:19 by lofiorin          #+#    #+#             */
/*   Updated: 2024/03/15 14:39:47 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"

# define IMG_WIDTH 32
# define IMG_HEIGHT 32
# define U 65362
# define D 65364
# define L 65361
# define R 65363
# define ESC 65307

typedef struct s_coord
{
	int		x;
	int		y;
}	t_coord;

typedef struct s_img
{
	void	*exit[2];
	void	*wall;
	void	*coll;
	void	*floor;
	void	*player[4];
	void	*banner;
}	t_img;

typedef struct s_parsing
{
	int		collectable;
	int		player;
	int		exit;
	int		exit_found;
	t_coord	player_pos;
	char	**map;
	int		wit;
}	t_parsing;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	**map;
	int		collectable;
	t_coord	player_pos;
	int		moves;
}	t_data;

void	put_img(t_data *window, void *img, int x, int y);
void	ft_free_map(char **map);
int		ft_clean_exit(t_data *window, int status);
int		ft_move_check(t_data *window, int x, int y, char entity);
int		ft_movement(int keycode, t_data *window);
int		ft_map_gen(t_data *window, char *file_name);
void	ft_render(t_data *window);
void	ft_select_image(t_data *window, char c, int x, int y);
int		count_map_lines(char **map);
int		ft_control_shape(char **map);
int		ft_control_walls(char **map);
int		ft_final_control(t_parsing *control);
int		ft_parsing(t_data *window);

#endif
