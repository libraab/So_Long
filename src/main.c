/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/16 19:51:15 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include "../header/mlx_keycode.h"

int nocolectible_is_true(char **map)
{
	int y = -1;
	int x = -1;

	while (map[++y])
		while (map[y][++x])
			if (map[y][x] == 'C')
				return (0);
	return (1);
}

void	ft_print_map(t_main *win)
{
	int y;
	int x;
	int j;

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
			else if (win->map[y][x] == 'E')
			{
				if (nocolectible_is_true(win->map))
				{
					ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
					ft_put_image_to_image(&win->map_img, &win->exit_out, x * 50, y * 50);
				}
				else
				{
					ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
					ft_put_image_to_image(&win->map_img, &win->exit,  x * 50, y * 50);
				}
			}
			else if (win->map[y][x] == 'C')
			{
				ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
				ft_put_image_to_image(&win->map_img, &win->ha, x * 50, y * 50);
			}
			else if (win->map[y][x] == 'P')
			{
				ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
				ft_put_image_to_image(&win->map_img, &win->player_right, x * 50, y * 50);
				win->player_pos.x = x * 50;
				win->player_pos.y = y * 50;
			}
		}
	}
	j = 0;
	while (win->map[j])
	{
		printf("%s\n", win->map[j]);
		j++;
	}
}

int	get_height(char *file)
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

int	get_width(char *file)
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

int deal_key(int key, t_main *win)
{
	ft_put_image_to_image(&win->map_img, &win->ground, win->player_pos.x, win->player_pos.y);
   if (key == KEY_ECHAP)
        exit(53);
	else if (key == KEY_A)
	{
		if (win->player_pos.x >= 50
			&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != '1' && win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != 'E')
			win->player_pos.x -= 50;
		else if (win->player_pos.x >= 50
			&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != '1' && nocolectible_is_true(win->map))
			win->player_pos.x -= 50;
	}
	else if (key == KEY_D)
	{
		if (win->player_pos.x >= 50
			&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 + 1] != '1' && win->map[win->player_pos.y / 50][win->player_pos.x / 50 + 1] != 'E')
			win->player_pos.x += 50;
		else if (win->player_pos.x >= 50
			&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 + 1] != '1' && nocolectible_is_true(win->map))
			win->player_pos.x += 50;
	}
	else if (key == KEY_W)
	{
		if (win->player_pos.y >= 50
			&& win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != '1' && win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != 'E')
			win->player_pos.y -= 50;
		else if (win->player_pos.y >= 50
			&& win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != '1' && nocolectible_is_true(win->map))
			win->player_pos.y -= 50;
	}
	else if (key == KEY_S)
	{
		if (win->player_pos.y >= 50
			&& win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != '1' && win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != 'E')
			win->player_pos.y += 50;
		else if (win->player_pos.y >= 50
			&& win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != '1' && nocolectible_is_true(win->map))
			win->player_pos.y += 50;
	}
	ft_put_image_to_image(&win->map_img, &win->player_right, win->player_pos.x, win->player_pos.y);

	if (win->map[win->player_pos.y / 50][win->player_pos.x / 50] == 'C')
		win->map[win->player_pos.y / 50][win->player_pos.x / 50] = '0';
	
	if (nocolectible_is_true(win->map))
	{
		ft_put_image_to_image(&win->map_img, &win->player_right, win->player_pos.x, win->player_pos.y);
		/*if (win->map[win->player_pos.y / 50][win->player_pos.x / 50] == 'E')
			ft_game_over();*/
	}
	int y_win = 0; //camera position when moving 
	int x_win = 0;
		
		if (win->player_pos.y > 400)
		{
			if (win->player_pos.y > win->map_img.height - 350)
				y_win = - win->map_img.height + 550;
			else
				y_win = - win->player_pos.y + 200;
			
		}
		if (win->player_pos.x > 450)
		{
			if (win->player_pos.x > win->map_img.width - 350)
			 	x_win = - win->map_img.width + 500;
			else
				x_win = - win->player_pos.x + 200;
		}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->map_img.img, x_win, y_win);
    return (0);
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
		win.map_img.height = get_height(av[1]) * 50;
		win.map_img.width = get_width(av[1]) * 50;
		if (win.map_img.height < 500 && win.map_img.width < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.width, win.map_img.height, "so_long");
		else if (win.map_img.width < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.width, 500, "so_long");
		else if (win.map_img.height < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, 500, win.map_img.height, "so_long");
		else
			win.win_ptr = mlx_new_window(win.mlx_ptr, 500, 500, "so_long");
		win.map_img.img = mlx_new_image(win.mlx_ptr, win.map_img.width, win.map_img.height);
		ft_print_map(&win);
		mlx_hook(win.win_ptr, 2, 1L<<0, deal_key, &win);
		
		int y_win = 0; //camera starting position 
		int x_win = 0;
		
		if (win.player_pos.y > 450)
		{
			if (win.player_pos.y > win.map_img.height - 350)
				y_win = - win.map_img.height + 500;
			else
				y_win = - win.player_pos.y + 200;
		}
		if (win.player_pos.x > 450)
		{
			if (win.player_pos.x > win.map_img.width - 350)
			 	x_win = - win.map_img.width + 500;
			else
				x_win = - win.player_pos.x + 200;
		}
		mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.map_img.img, x_win, y_win);
		mlx_loop(win.mlx_ptr);
	}
	return (0);
}
