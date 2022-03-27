/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:40:02 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/06 15:41:46 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_camera(t_main *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (win->p_pos.y > 450)
	{
		if (win->p_pos.y > win->map_img.he - 350)
			y = -win->map_img.he + 500;
		else
			y = -win->p_pos.y + 200;
	}
	if (win->p_pos.x > 450)
	{
		if (win->p_pos.x > win->map_img.wi - 350)
			x = -win->map_img.wi + 500;
		else
			x = -win->p_pos.x + 200;
	}
	if (!win->victory)
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->map_img.img, x, y);
}
