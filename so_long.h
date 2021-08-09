/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:50:28 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/09 16:50:26 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

#define SO_LONG_H

#include "mlx.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define BUFFER_SIZE 1

 typedef struct s_hero
 {
      void    *img;
      int     width;
      int     height;
 }           t_asma;

typedef struct s_wall
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		step;
	t_asma	wall1;
	t_asma	wall2;
	t_asma	asma;
	t_asma	map_img;
	char	**map;
}				t_bank;

void ft_background(t_bank *s, int x, int y);
void	ft_figure(int key, void *s);
int		deal_key(int key, void *param);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void    ft_pars(t_bank *a, char **av);

#endif
