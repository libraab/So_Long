/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2022/03/27 18:59:33 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_nocolectible_is_true(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'C')
				return (0);
	}
	return (1);
}

int	ft_get_height(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	i++;
	free(line);
	close (fd);
	return (i);
}

int	ft_get_width(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	i = ft_strlen(line);
	free(line);
	close (fd);
	return (i);
}

void	ft_so_long(t_main *win, char *av)
{
	win->map_img.he = ft_get_height(av) * 50;
	win->map_img.wi = ft_get_width(av) * 50;
	win->mlx_ptr = mlx_init();
	ft_define_img(win);
	if (win->map_img.he < 500 && win->map_img.wi < 500)
		win->win_ptr = mlx_new_window(win->mlx_ptr, win->map_img.wi,
				win->map_img.he, "so_long");
	else if (win->map_img.wi < 500)
		win->win_ptr = mlx_new_window(win->mlx_ptr,
				win->map_img.wi, 500, "so_long");
	else if (win->map_img.he < 500)
		win->win_ptr = mlx_new_window(win->mlx_ptr, 500,
				win->map_img.he, "so_long");
	else
		win->win_ptr = mlx_new_window(win->mlx_ptr, 500, 500, "so_long");
	win->map_img.img = mlx_new_image(win->mlx_ptr, win->map_img.wi + 50,
			win->map_img.he + 50);
	ft_print_map(win);
	mlx_hook(win->win_ptr, 17, 0, ft_exit, win);
	mlx_loop_hook(win->win_ptr, ft_ennemy_move, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, ft_deal_key, win);
	mlx_hook(win->win_ptr, 3, 1L << 1, ft_release_key, win);
	ft_camera(win);
	mlx_loop(win->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_main	win;

	win.victory = 0;
	win.state_pose = 0;
	win.all_steps = 1;
	if (ac != 2)
		return (ft_errors(6));
	if (ft_parsing(&win, av[1]))
		ft_so_long(&win, av[1]);
	return (0);
}
