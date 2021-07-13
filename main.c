/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/13 20:10:07 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	printf("Key event %d\n", key);
    //ft_putchar('X');
	return (0);
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int i;
	int j;
    int k;
	
	i = 0;
    k = 50;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400, 400, "My Game");
	while (i <= 50)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, 200 + i, 200, 0x00FF0000);
        mlx_pixel_put(mlx_ptr, win_ptr, 200, 200 + i, 0x00FF0000);
        mlx_pixel_put(mlx_ptr, win_ptr, 200 + i, 250, 0x00FF0000);
        mlx_pixel_put(mlx_ptr, win_ptr, 250, 250 - i, 0x00FF0000);
        i++;
    }
    while (k < 150)
    {
        j = 50;
        while(j<150)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, j, k, 0x00FF0000);
            j++;
        }
        k++;
    }
    mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}