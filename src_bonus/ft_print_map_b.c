/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:48:15 by abouhlel          #+#    #+#             */
/*   Updated: 2022/03/27 20:18:34 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_print_player(t_main *win, int x, int y)
{
	ft_put_img(&win->map_img, &win->ground, x * 50, y * 50);
	ft_put_img(&win->map_img, &win->p_r, x * 50, y * 50);
	win->p_pos.x = x * 50;
	win->p_pos.y = y * 50;
}

void	ft_print_ennemy(t_main *win, int x, int y)
{
	ft_put_img(&win->map_img, &win->ground, x * 50, y * 50);
	ft_put_img(&win->map_img, &win->pig, x * 50, y * 50);
	win->p_pos.x = x * 50;
	win->p_pos.y = y * 50;
}

void	ft_print_exit(t_main *win, int x, int y)
{
	if (ft_nocolectible_is_true(win->map))
	{
		ft_put_img(&win->map_img, &win->ground, x * 50, y * 50);
		ft_put_img(&win->map_img, &win->exit2, x * 50, y * 50);
	}
	else if (!ft_nocolectible_is_true(win->map))
	{
		ft_put_img(&win->map_img, &win->ground, x * 50, y * 50);
		ft_put_img(&win->map_img, &win->exit, x * 50, y * 50);
	}
}

void	ft_print_map(t_main *win)
{
	int	y;
	int	x;

	y = -1;
	while (win->map[++y])
	{
		x = -1;
		while (win->map[y][++x])
		{
			if (win->map[y][x] == '0')
				ft_put_img(&win->map_img, &win->ground, x * 50, y * 50);
			else if (win->map[y][x] == '1')
				ft_put_img(&win->map_img, &win->wall, x * 50, y * 50);
			else if (win->map[y][x] == 'E')
				ft_print_exit(win, x, y);
			else if (win->map[y][x] == 'C')
			{
				ft_put_img(&win->map_img, &win->ground, x * 50, y * 50);
				ft_put_img(&win->map_img, &win->ha, x * 50, y * 50);
			}
			else if (win->map[y][x] == 'P')
				ft_print_player(win, x, y);
			else if (win->map[y][x] == 'K')
				ft_print_ennemy(win, x, y);
		}
	}
}

int	ft_ennemy_move(t_main *win)
{
	static int x = 0;
	int i;
	int j;

	i = 0;
	while (win->map[i])
	{
		j = 0;
		while(win->map[i][j])
		{
			if (win->map[i][j] == 'K' && x == 0)
			{
				win->map[i][j] = '0';
				win->map[i][j - 1] = 'K';
				x++;
			}
			else if (win->map[i][j] == 'K' && x > 0)
			{
				win->map[i][j] = '0';
				win->map[i][j + 1] = 'K';
				x--;
			}
			j++;
		}
		i++;
	}
	ft_print_map(win);
	return (0);
}