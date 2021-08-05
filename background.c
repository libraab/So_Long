/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:37:38 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/05 17:33:54 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

void    ft_background(t_bank *s, int x, int y)
{
    int k;
    
	k = 10;
    while (k < 500)//field_inside
    {
        y = 40;
        while(y < 950)
        {
            mlx_pixel_put(s->mlx_ptr, s->win_ptr, y, k, 0xFFC5E1);
            y++;
        }
        k++;
    }
	
    y = 0;
    while(x < 15)
	{
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->wall1.img, y, 0);//wall up
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->wall1.img, y, 494);//wall down
		x++;
		y = y + 89;
	}
	x = 44;
	y = 0;
	while(y < 10)
	{
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->wall2.img, 0, x);//wall left
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->wall2.img, 940, x);//wall right
		y++;
		x = x + 45;
	}
}
