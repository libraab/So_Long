/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/15 17:41:12 by abouhlel         ###   ########.fr       */
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
	int 	img1_width;
	int 	img1_height;
	int 	img2_width;
	int 	img2_height;
	//int 	img3_width;
	//int 	img3_height;
	char	*relative_path1 = "./chocolate.xpm";
	char	*relative_path2 = "./chocolate_v.xpm";
	//char	*relative_path3 = "./grass.xpm";
	void	*img1;
	void	*img2;
	//void	*img3;
	int		i;
	int		j;
	int		k;
    
    i = 0;
	j = 0;
	k = 0;
	s.mlx_ptr = mlx_init();
	s.win_ptr = mlx_new_window(s.mlx_ptr, 980, 525, "Asma's Game");
	mlx_key_hook(s.win_ptr, deal_key, (void *)&s);
	img1 = mlx_xpm_file_to_image(s.mlx_ptr, relative_path1, &img1_width, &img1_height);
	img2 = mlx_xpm_file_to_image(s.mlx_ptr, relative_path2, &img2_width, &img2_height);
	//img3 = mlx_xpm_file_to_image(s.mlx_ptr, relative_path3, &img3_width, &img3_height);
	ft_background(s, img1, img2, i, j);
	mlx_loop(s.mlx_ptr);
}