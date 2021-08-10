/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:50:28 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/10 18:13:32 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_data
{
	char		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

 typedef struct s_sprite
 {
      void    *img;
      int     width;
      int     height;
 }           t_sprite;

typedef struct s_main
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		step;
	t_sprite	ground;
	t_sprite	wall;
	t_sprite	player_up;
	t_sprite	player_down;
	t_sprite	player_left;
	t_sprite	player_left2;
	t_sprite	player_right;
	t_sprite	player_right2;
	t_sprite	map_img;
	char	**map;
}				t_main;

void	ft_put_image_to_image(t_sprite *dest, t_sprite *src, int x, int y);
void	ft_define_img(t_main *win);
int	ft_parsing(t_main *win, char *file);

#endif
