/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:40:02 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/25 20:16:40 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_camera(t_main *win, int x)
{
	int	x_win; 
	int	y_win;
    
	x_win = 0;
	y_win = 0;

	if(x == 0)//starting position 
	{
		if (win->player_pos.y > 450)
		{
			if (win->player_pos.y > win->map_img.height - 350)
				y_win = - win->map_img.height + 500;
			else
				y_win = - win->player_pos.y + 200;
		}
		if (win->player_pos.x > 450)
		{
			if (win->player_pos.x > win->map_img.width - 350)
				x_win = - win->map_img.width + 500;
			else
				x_win = - win->player_pos.x + 200;
		}
	}
	if(x == 1)//moving position
	{       
		if (win->player_pos.y > 400)
		{
			if (win->player_pos.y > win->map_img.height - 350)
				y_win = - win->map_img.height + 500;
			else
				y_win = - win->player_pos.y + 200;
        }
        if (win->player_pos.x > 450)
        {
        	if (win->player_pos.x > win->map_img.width - 350)
            	x_win = - win->map_img.width + 500;
            else
        	    x_win = - win->player_pos.x + 200;
        }
    }
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->map_img.img, x_win, y_win);
}