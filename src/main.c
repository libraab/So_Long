/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/03 20:33:19 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	nocolectible_is_true(char **map)
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

int	get_height(char *file)
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

int	get_width(char *file)
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

int release_key(int key, t_main *win)
{
	if (key == KEY_ECHAP)
        exit(53);
	if (!win->victory)
	{
		ft_put_img(&win->map_img, &win->ground, win->player_pos.x, win->player_pos.y);
		if (key == KEY_A)
		{
			
			ft_put_img(&win->map_img, &win->p_l, win->player_pos.x, win->player_pos.y);
		}
		else if (key == KEY_D)
		{
			if (win->state_pose)
			{
				win->state_pose = 0;
				ft_put_img(&win->map_img, &win->p_r, win->player_pos.x, win->player_pos.y);
			}
			else
			{
				win->state_pose = 1;
				ft_put_img(&win->map_img, &win->p_r2, win->player_pos.x, win->player_pos.y);
			}
		}
		else if (key == KEY_W)
		{
			ft_put_img(&win->map_img, &win->p_up, win->player_pos.x, win->player_pos.y);
		}
		else if (key == KEY_S)
		{
			
			ft_put_img(&win->map_img, &win->p_down, win->player_pos.x, win->player_pos.y);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_main	win;

	win.victory = 0;
	win.state_pose = 0;
	if (ac != 2)
		return (0);
	if (ft_parsing(&win, av[1]))
	{
		printf("%d %d\n", get_width(av[1]), get_height(av[1]));
		win.map_img.height = get_height(av[1]) * 50;
		win.map_img.width = get_width(av[1]) * 50;
		win.mlx_ptr = mlx_init();
		ft_define_img(&win);
		if (win.map_img.height < 500 && win.map_img.width < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.width, win.map_img.height, "so_long");
		else if (win.map_img.width < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.width, 500, "so_long");
		else if (win.map_img.height < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, 500, win.map_img.height, "so_long");
		else
			win.win_ptr = mlx_new_window(win.mlx_ptr, 500, 500, "so_long");
		win.map_img.img = mlx_new_image(win.mlx_ptr, win.map_img.width + 50, win.map_img.height + 50);
		ft_print_map(&win);
		mlx_hook(win.win_ptr, 2, 1L << 0, deal_key, &win);
		mlx_hook(win.win_ptr, 3, 1L << 1, release_key, &win);
		ft_camera(&win);
		mlx_loop(win.mlx_ptr);
	}
	return (0);
}
