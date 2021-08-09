/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/09 19:50:35 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*
	La fonction ft_put_image_to_image bug, faut voir avec mathieu
	J'ai import mon GNL il etait pas dans ta libft
*/

void	ft_print_map(t_main *win)
{
	int y;
	int x;

	y = -1;
	while (win->map[++y])
	{
		x = -1;
		while (win->map[y][++x])
		{
			if (win->map[y][x] == 'P')
				ft_put_image_to_image(&win->map_img, &win->player_left, x * 50, y * 50);
			// else if (win->map[y][x] == '1')
			// 	ft_put_image_to_image(&win->map_img, &win->wall,  x * 50, y * 50);
			// else if (win->map[y][x] == 'P')
			// 	ft_put_image_to_image(&win->map_img, &win->player_right, x * 50, y * 50);
		}
	}
	for (int j = 0;win->map[j];j++)
		printf("%s\n", win->map[j]);
}

int	main(int ac, char **av)
{
	t_main	win;

	if (ac != 2)
		return (0);
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 500, 500, "so_long");
	ft_define_img(&win);
	if (ft_parsing(&win, av[1]))
	{
		win.map_img.img = mlx_new_image(win.mlx_ptr, win.map_img.height, win.map_img.width);
		ft_print_map(&win);
		mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.map_img.img, 0, 0);
		mlx_loop(win.mlx_ptr);
	}
	return (0);
}
