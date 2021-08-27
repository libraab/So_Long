/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:40:02 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/27 21:18:43 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_camera(t_main *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (win->player_pos.y > 450)
	{
		if (win->player_pos.y > win->map_img.height - 350)
			y = -win->map_img.height + 500;
		else
			y = -win->player_pos.y + 200;
	}
	if (win->player_pos.x > 450)
	{
		if (win->player_pos.x > win->map_img.width - 350)
			x = -win->map_img.width + 500;
		else
			x = -win->player_pos.x + 200;
	}
	if (!win->victory)
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->map_img.img, x, y);
}
