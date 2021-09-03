/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:33:12 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/03 18:53:13 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_up(t_main *win)
{
	if (win->player_pos.y >= 50 && win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != '1' && win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != 'E')
				win->player_pos.y -= 50;
	else if (win->player_pos.y >= 50 && win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != '1' && nocolectible_is_true(win->map))
				win->player_pos.y -= 50;
	ft_put_image_to_image(&win->map_img, &win->player_up, win->player_pos.x, win->player_pos.y);
}

void	ft_down(t_main *win)
{
	if (win->player_pos.y >= 50 && win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != '1' && win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != 'E')
		win->player_pos.y += 50;
	else if (win->player_pos.y >= 50 && win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != '1' && nocolectible_is_true(win->map))
		win->player_pos.y += 50;
	ft_put_image_to_image(&win->map_img, &win->player_down, win->player_pos.x, win->player_pos.y);
}

void	ft_left(t_main *win, int step)
{
	if (win->player_pos.x >= 50 && win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != '1' && win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != 'E')
		win->player_pos.x -= 50;
	else if (win->player_pos.x >= 50 && win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != '1' && nocolectible_is_true(win->map))
		win->player_pos.x -= 50;
	if (step % 5 == 0)
		ft_put_image_to_image(&win->map_img, &win->player_left, win->player_pos.x, win->player_pos.y);
	else
		ft_put_image_to_image(&win->map_img, &win->player_left2, win->player_pos.x, win->player_pos.y);
}

void	ft_right(t_main *win, int step)
{
	if (win->player_pos.x >= 50 && win->map[win->player_pos.y / 50][win->player_pos.x / 50 + 1] != '1' && win->map[win->player_pos.y / 50][win->player_pos.x / 50 + 1] != 'E')
		win->player_pos.x += 50;
	else if (win->player_pos.x >= 50 && win->map[win->player_pos.y / 50][win->player_pos.x / 50+1] != '1' && nocolectible_is_true(win->map))
		win->player_pos.x += 50;
	if (step % 5 == 0)
		ft_put_image_to_image(&win->map_img, &win->player_right, win->player_pos.x, win->player_pos.y);
	else
		ft_put_image_to_image(&win->map_img, &win->player_right2, win->player_pos.x, win->player_pos.y);
}

int	deal_key(int key, t_main *win)
{
	int			x;
	int			y;
	static int	col = 0;
	static int	step = 1;

	printf("%d\n", step++);
	if (key == KEY_ECHAP)
		exit(53);
	if (!win->victory)
	{
		ft_put_image_to_image(&win->map_img, &win->ground,
			win->player_pos.x, win->player_pos.y);
		if (key == KEY_A)
			ft_left(win, step);
		else if (key == KEY_D)
			ft_right(win, step);
		else if (key == KEY_W)
			ft_up(win);
		else if (key == KEY_S)
			ft_down(win);
		if (win->map[win->player_pos.y / 50][win->player_pos.x / 50] == 'C')
			win->map[win->player_pos.y / 50][win->player_pos.x / 50] = '0';
		if (nocolectible_is_true(win->map))
			col = 1;
		if (col == 1)
		{
			y = -1;
			while (win->map[++y])
			{
				x = -1;
				while (win->map[y][++x])
				{
					if (win->map[y][x] == 'E')
					{
						ft_put_image_to_image(&win->map_img,
							&win->ground, x * 50, y * 50);
						ft_put_image_to_image(&win->map_img,
							&win->exit_out, x * 50, y * 50);
					}
				}
			}
			col++;
		}
		if (win->map[win->player_pos.y / 50][win->player_pos.x / 50] == 'E')
		{
			ft_game_over(win, 0);
			win->victory = 1;
		}
		if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
			ft_camera(win);
	}
	return (0);
}
