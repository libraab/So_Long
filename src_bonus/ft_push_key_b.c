/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_key_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:33:12 by abouhlel          #+#    #+#             */
/*   Updated: 2022/03/27 18:56:51 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_open_door(t_main *w)
{
	int			x;
	int			y;

	y = -1;
	while (w->map[++y])
	{
		x = -1;
		while (w->map[y][++x])
		{
			if (w->map[y][x] == 'E')
			{
				ft_put_img(&w->map_img, &w->ground, x * 50, y * 50);
				ft_put_img(&w->map_img, &w->exit2, x * 50, y * 50);
			}
		}
	}
	w->my_ha++;
}

int	ft_deal_key(int key, t_main *w)
{
	static int	step = 1;

	w->my_ha = 0;
	if (key == KEY_ECHAP)
		exit(0);
	if (!w->victory)
	{
		step++;
		if (key == KEY_A)
			ft_left(w, step);
		else if (key == KEY_D)
			ft_right(w, step);
		else if (key == KEY_W)
			ft_up(w);
		else if (key == KEY_S)
			ft_down(w);
		if (w->map[w->p_pos.y / 50][w->p_pos.x / 50] == 'C')
			w->map[w->p_pos.y / 50][w->p_pos.x / 50] = '0';
		w->my_ha = ft_nocolectible_is_true(w->map);
		if (w->my_ha == 1)
			ft_open_door(w);
		if (w->map[w->p_pos.y / 50][w->p_pos.x / 50] == 'E')
			ft_game_over(w, 0);
	}
	return (0);
}

int	ft_release_key(int key, t_main *w)
{
	if (!w->victory && key != KEY_ECHAP)
	{
		ft_put_img(&w->map_img, &w->ground, w->p_pos.x, w->p_pos.y);
		if (key == KEY_A)
			ft_put_img(&w->map_img, &w->p_l, w->p_pos.x, w->p_pos.y);
		else if (key == KEY_D)
		{
			if (w->state_pose)
			{
				w->state_pose = 0;
				ft_put_img(&w->map_img, &w->p_r, w->p_pos.x, w->p_pos.y);
			}
			else
			{
				w->state_pose = 1;
				ft_put_img(&w->map_img, &w->p_r2, w->p_pos.x, w->p_pos.y);
			}
		}
		else if (key == KEY_W)
			ft_put_img(&w->map_img, &w->p_up, w->p_pos.x, w->p_pos.y);
		else if (key == KEY_S)
			ft_put_img(&w->map_img, &w->p_down, w->p_pos.x, w->p_pos.y);
	}
	return (0);
}
