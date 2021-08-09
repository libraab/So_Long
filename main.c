/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/09 16:35:38 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

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
	t_bank	*d;
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

typedef struct	s_data {
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	ft_pixel_put(t_data *data, int x, int y, int color)//to get the pixel and copy it into the image
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	ft_pixel_get(t_data *data, int x, int y)//to get the color
{
	return *(unsigned int*)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));
}

void	ft_put_image_to_image(t_asma *dest, t_asma *src, int x, int y)
{
	t_data img_src;
	t_data img_dst;
	int	xx;
	int yy;

	img_src.addr = mlx_get_data_addr(src->img, &img_src.bits_per_pixel, &img_src.line_length, &img_src.endian);
	img_dst.addr = mlx_get_data_addr(dest->img, &img_dst.bits_per_pixel, &img_dst.line_length, &img_dst.endian);
	
	yy = 0;
	while (yy < src->height)
	{
		xx = 0;
		while (xx < src->width)
		{
			if(xx + x > dest->width || xx + x < 0 || yy + y > dest->height || yy + y < 0)
				printf("error asma tu dec\n");
			else
				ft_pixel_put(&img_dst, xx + x, yy + y, ft_pixel_get(&img_src, xx, yy));
			xx++;
		}
		yy++;
	}
}

int	main(int ac, char **av)
{
	t_bank	s;
	int		i;
	int		j;
	int		k;
    
    i = 0;
	j = 0;
	k = 0;
	if (ac != 2)
		return (0);
	s.mlx_ptr = mlx_init();
	s.win_ptr = mlx_new_window(s.mlx_ptr, 980, 540, "Asma's World");
	// mlx_key_hook(s.win_ptr, deal_key, (void *)&s);
	// s.wall1.img = mlx_xpm_file_to_image(s.mlx_ptr, "./choc.xpm", &s.wall1.width, &s.wall1.height);
	s.wall2.img = mlx_xpm_file_to_image(s.mlx_ptr, "./dada.xpm", &s.wall2.width, &s.wall2.height);
	// s.asma.img = mlx_xpm_file_to_image(s.mlx_ptr, "./f.xpm", &s.asma.width, &s.asma.height);
	// ft_background(&s, i, j);
	//char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
	// test.height = 1000;
	// test.width = 1000;
	ft_pars(&s, av);
	s.map_img.img = mlx_new_image(s.mlx_ptr, s.map_img.height, s.map_img.width);
	while (i < 300)
	{
		ft_put_image_to_image(&s.map_img, &s.wall2, 0, i);
		i = i + 40;
	}
	
	mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, s.map_img.img, 0, 0);
	mlx_loop(s.mlx_ptr);
}
