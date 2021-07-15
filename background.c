/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:37:38 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/15 13:47:25 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

void    ft_background(struct s, void *img, int x, int y)
{
    int i;
    int j;
    int k;
    
    i = 0;
	j = 0;
	k = 49;
    while(i < 20)
	{
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img, j, 0);
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img, j, 450);
		i++;
		j = j + 49;
	}
	i = 49;
	j = 0;
	while(j < 20)
	{
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img, 0, i);
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img, 930, i);
		j++;
		i = i + 20;
	}
	while (k < 450)
    {
        j = 49;
        while(j < 930)
        {
            mlx_pixel_put(s.mlx_ptr, s.win_ptr, j, k, 0xAD452F);
            j++;
        }
        k++;
    }
}