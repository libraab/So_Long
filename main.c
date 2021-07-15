/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/15 13:57:14 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	x;
    
    x = nb;
	if (x < 0)
	{
		x = x * -1;
		ft_putchar('-');
	}
	if (x > 9)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
	{
		ft_putchar(x + '0');
	}
}

/*void	ft_letters(int key)
{
	if (key == 0)
		ft_putchar('a');
	if (key == 11)
		ft_putchar('b');
	if (key == 8)
		ft_putchar('c');
	if (key == 2)
		ft_putchar('d');
	if (key == 14)
		ft_putchar('e');
	if (key == 3)
		ft_putchar('f');
	if (key == 5)
		ft_putchar('g');
	if (key == 4)
		ft_putchar('h');
	if (key == 34)
		ft_putchar('i');
	if (key == 38)
		ft_putchar('i');
	if (key == 40)
		ft_putchar('k');
	if (key == 37)
		ft_putchar('l');
	if (key == 46)
		ft_putchar('m');
	if (key == 45)
		ft_putchar('n');
	if (key == 31)
		ft_putchar('o');
	if (key == 35)
		ft_putchar('p');
	if (key == 12)
		ft_putchar('q');
	if (key == 15)
		ft_putchar('r');
	if (key == 1)
		ft_putchar('s');
	if (key == 17)
		ft_putchar('t');
	if (key == 32)
		ft_putchar('u');
	if (key == 13)
		ft_putchar('w');
	if (key == 7)
		ft_putchar('x');
	if (key == 16)
		ft_putchar('y');
	if (key == 6)
		ft_putchar('z');
	if (key == 49)
		ft_putchar(' ');
}*/

void	ft_figure(int key, void *s)
{
	int i;
	int	j;
	bank	*d;
	static int	pos_x = 200;
	static int	pos_y = 200;
    
    d = s;
	i = 0;
	j = 0;
	if (key == 53)
		exit(53);
	else if (key == 2)
		pos_x++;
	else if (key == 0)
		pos_x--;
	else if (key == 13)
		pos_y--;
	else if (1)
		pos_y++;
	mlx_pixel_put(d->mlx_ptr, d->win_ptr, pos_x, pos_y, 0xFFFFFF);
}

int	deal_key(int key, void *param)
{
	ft_figure(key, param);
	return (0);
}

int	main()
{
	bank	s;
	int 	img_width;
	int 	img_height;
	char	*relative_path = "./brick_wall_49x49.xpm";
	void	*img;
	int		i;
	int		j;
	int		k;
    
    i = 0;
	j = 0;
	k = 0;
	s.mlx_ptr = mlx_init();
	s.win_ptr = mlx_new_window(s.mlx_ptr, 980, 500, "Coucou c'est nous");
	mlx_key_hook(s.win_ptr, deal_key, (void *)&s);
	img = mlx_xpm_file_to_image(s.mlx_ptr, relative_path, &img_width, &img_height);
	//ft_background(s, img, j, i);
	while(i < 20)
	{
		mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, img, j, 15);
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
	while (k < 15)
    {
        j = 0;
        while(j < 1000)
        {
            mlx_pixel_put(s.mlx_ptr, s.win_ptr, j, k, 0xAD452F);
            j++;
        }
        k++;
    }
	while (k < 15)
    {
        j = 450;
        while(j < 1000)
        {
            mlx_pixel_put(s.mlx_ptr, s.win_ptr, j, k, 0xAD452F);
            j++;
        }
        k++;
    }
	/*while (k < 450)
    {
        j = 49;
        while(j < 930)
        {
            mlx_pixel_put(s.mlx_ptr, s.win_ptr, j, k, 0xAD452F);
            j++;
        }
        k++;
    }*/
	mlx_loop(s.mlx_ptr);
}