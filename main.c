/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/05 17:34:07 by abouhlel         ###   ########.fr       */
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

int	main()
{
	t_bank	s;
	int		i;
	int		j;
	int		k;
    
    i = 0;
	j = 0;
	k = 0;
	s.mlx_ptr = mlx_init();
	s.win_ptr = mlx_new_window(s.mlx_ptr, 980, 540, "Asma's World");
	//mlx_key_hook(s.win_ptr, deal_key, (void *)&s);
	s.wall1.img = mlx_xpm_file_to_image(s.mlx_ptr, "./choc.xpm", &s.wall1.width, &s.wall1.height);
	s.wall2.img = mlx_xpm_file_to_image(s.mlx_ptr, "./choc2.xpm", &s.wall2.width, &s.wall2.height);
	s.asma.img = mlx_xpm_file_to_image(s.mlx_ptr, "./f.xpm", &s.asma.width, &s.asma.height);
	ft_background(&s, i, j);
	mlx_loop(s.mlx_ptr);
}
