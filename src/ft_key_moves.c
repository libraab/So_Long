/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:06:50 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/06 21:57:11 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_up(t_main *w)
{
	ft_put_img(&w->map_img, &w->ground, w->p_pos.x, w->p_pos.y);
	if (w->p_pos.y >= 50 && w->map[w->p_pos.y / 50 - 1][w->p_pos.x / 50]
		!= '1' && w->map[w->p_pos.y / 50 - 1][w->p_pos.x / 50] != 'E')
		w->p_pos.y -= 50;
	else if (w->p_pos.y >= 50 && w->map[w->p_pos.y / 50 - 1][w->p_pos.x / 50]
		!= '1' && ft_nocolectible_is_true(w->map))
		w->p_pos.y -= 50;
	ft_put_img(&w->map_img, &w->p_up, w->p_pos.x, w->p_pos.y);
	ft_camera(w);
}

void	ft_down(t_main *w)
{
	ft_put_img(&w->map_img, &w->ground, w->p_pos.x, w->p_pos.y);
	if (w->p_pos.y >= 50 && w->map[w->p_pos.y / 50 + 1][w->p_pos.x / 50]
		!= '1' && w->map[w->p_pos.y / 50 + 1][w->p_pos.x / 50] != 'E')
		w->p_pos.y += 50;
	else if (w->p_pos.y >= 50 && w->map[w->p_pos.y / 50 + 1][w->p_pos.x / 50]
		!= '1' && ft_nocolectible_is_true(w->map))
		w->p_pos.y += 50;
	ft_put_img(&w->map_img, &w->p_down, w->p_pos.x, w->p_pos.y);
	ft_camera(w);
}

void	ft_left(t_main *w, int step)
{
	ft_put_img(&w->map_img, &w->ground, w->p_pos.x, w->p_pos.y);
	if (w->p_pos.x >= 50 && w->map[w->p_pos.y / 50][w->p_pos.x / 50 - 1]
		!= '1' && w->map[w->p_pos.y / 50][w->p_pos.x / 50 - 1] != 'E')
		w->p_pos.x -= 50;
	else if (w->p_pos.x >= 50 && w->map[w->p_pos.y / 50][w->p_pos.x / 50 - 1]
		!= '1' && ft_nocolectible_is_true(w->map))
		w->p_pos.x -= 50;
	if (step % 5 == 0)
		ft_put_img(&w->map_img, &w->p_l, w->p_pos.x, w->p_pos.y);
	else
		ft_put_img(&w->map_img, &w->p_l2, w->p_pos.x, w->p_pos.y);
	ft_camera(w);
}

void	ft_right(t_main *w, int step)
{
	ft_put_img(&w->map_img, &w->ground, w->p_pos.x, w->p_pos.y);
	if (w->p_pos.x >= 50 && w->map[w->p_pos.y / 50][w->p_pos.x / 50 + 1]
		!= '1' && w->map[w->p_pos.y / 50][w->p_pos.x / 50 + 1] != 'E')
		w->p_pos.x += 50;
	else if (w->p_pos.x >= 50 && w->map[w->p_pos.y / 50][w->p_pos.x / 50 + 1]
		!= '1' && ft_nocolectible_is_true(w->map))
		w->p_pos.x += 50;
	if (step % 5 == 0)
		ft_put_img(&w->map_img, &w->p_r, w->p_pos.x, w->p_pos.y);
	else
		ft_put_img(&w->map_img, &w->p_r2, w->p_pos.x, w->p_pos.y);
	ft_camera(w);
}
