/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:37:38 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/15 16:08:57 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

void    ft_background(bank s, void *img1, void *img2, int x, int y)
{
    int k;
    
	k = 49;
    while (k < 479)//field_inside
    {
        y = 51;
        while(y < 930)
        {
            mlx_pixel_put(s.mlx_ptr, s.win_ptr, y, k, 0x2ECC71);
            y++;
        }
        k++;
    }
    y = 0;
    while(x < 20)
	{
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img1, y, 0);//wall up
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img1, y, 479);//wall down
		x++;
		y = y + 49;
	}
	x = 49;
	y = 0;
	while(y < 20)
	{
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img2, 0, x);//wall left
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img2, 930, x);//wall right
		y++;
		x = x + 20;
	}
}