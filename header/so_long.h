/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:50:28 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/03 20:28:11 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx.h"
# include "../libft/libft.h"
# include "../header/mlx_keycode.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_sprite
{
	void	*img;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_main
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			step;
	t_pos		player_pos;
	t_sprite	ground;
	t_sprite	ha;
	t_sprite	pig;
	t_sprite	wall;
	t_sprite	exit;
	t_sprite	exit2;
	t_sprite	p_up;
	t_sprite	p_down;
	t_sprite	p_l;
	t_sprite	p_l2;
	t_sprite	p_r;
	t_sprite	p_r2;
	t_sprite	map_img;
	char		**map;
	int			victory;
	int			state_pose;
}				t_main;

void	ft_put_img(t_sprite *dest, t_sprite *src, int x, int y);
void	ft_define_img(t_main *win);
void	ft_print_map(t_main *win);
int		nocolectible_is_true(char **map);
int		ft_parsing(t_main *win, char *file);
int		deal_key(int key, t_main *win);
int		ft_game_over(t_main *win, int x);
void	ft_camera(t_main *win);
#endif
