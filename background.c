/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:37:38 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/15 15:05:11 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

void    ft_background(bank s, void *img, int x, int y)
{
    int k;
    
	k = 49;
    while(x < 20)
	{
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img, y, 0);
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img, y, 450);
		x++;
		y = y + 49;
	}
	x = 49;
	y = 0;
	while(y < 20)
	{
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img, 0, x);
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img, 930, x);
		y++;
		x = x + 20;
	}
	while (k < 450)
    {
        y = 49;
        while(y < 930)
        {
            mlx_pixel_put(s.mlx_ptr, s.win_ptr, y, k, 0xAD452F);
            y++;
        }
        k++;
    }
}