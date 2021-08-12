/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/10 18:40:07 by bledda           ###   ########.fr       */
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
			if (win->map[y][x] == '0')
				ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
			else if (win->map[y][x] == '1')
				ft_put_image_to_image(&win->map_img, &win->wall,  x * 50, y * 50);
			else if (win->map[y][x] == 'P')
			{
				ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
				ft_put_image_to_image(&win->map_img, &win->player_right, x * 50, y * 50);
			}
		}
	}
	for (int j = 0;win->map[j];j++)
		printf("%s\n", win->map[j]);
}

int	get_width(char *file)
{
	int fd;
	int count;
	char *line;

	count = 0;
	fd =  open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		count++;
		free(line);
	}
	count++;
	close (fd);
	return (count);
}

int	get_height(char *file)
{
	int fd;
	int i;
	char *line;

	i = 0;
	fd =  open(file, O_RDONLY);
	get_next_line(fd, &line);
	i = ft_strlen(line);
	free(line);
	close (fd);
	return (i);
}

int	main(int ac, char **av)
{
	t_main	win;

	if (ac != 2)
		return (0);
	win.mlx_ptr = mlx_init();
	ft_define_img(&win);
	if (ft_parsing(&win, av[1]))
	{
		printf ("%d %d\n", get_width(av[1]), get_height(av[1]));
		win.map_img.width = get_width(av[1]) * 50;
		win.map_img.height = get_height(av[1]) * 50;
		if (win.map_img.width < 500 && win.map_img.height < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.height, win.map_img.width, "so_long");
		else if (win.map_img.height < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.height, 500, "so_long");
		else if (win.map_img.width < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, 500, win.map_img.width, "so_long");
		else
			win.win_ptr = mlx_new_window(win.mlx_ptr, 500, 500, "so_long");
		win.map_img.img = mlx_new_image(win.mlx_ptr, win.map_img.height, win.map_img.width);
		ft_print_map(&win);
		mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.map_img.img, 0, 0);
		mlx_loop(win.mlx_ptr);
	}
	return (0);
}
