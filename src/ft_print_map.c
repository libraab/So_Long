/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:48:15 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/27 10:49:54 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

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
				ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
			else if (win->map[y][x] == '1')
				ft_put_image_to_image(&win->map_img, &win->wall, x * 50, y * 50);
			else if (win->map[y][x] == 'E')
			{
				if (nocolectible_is_true(win->map))
				{
					ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
					ft_put_image_to_image(&win->map_img, &win->exit_out, x * 50, y * 50);
				}
				else if (!nocolectible_is_true(win->map))
				{
					ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
					ft_put_image_to_image(&win->map_img, &win->exit, x * 50, y * 50);
				}
			}
			else if (win->map[y][x] == 'C')
			{
				ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
				ft_put_image_to_image(&win->map_img, &win->ha, x * 50, y * 50);
			}
			else if (win->map[y][x] == 'P')
			{
				ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
				ft_put_image_to_image(&win->map_img, &win->player_right, x * 50, y * 50);
				win->player_pos.x = x * 50;
				win->player_pos.y = y * 50;
			}
		}
	}
}
