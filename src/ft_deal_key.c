/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:04:34 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/25 20:09:26 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int deal_key(int key, t_main *win)
{
	int x;
	int y;
	static int col = 0;
	static int step	= 0;

	step++;
	if (step == 4)
	{
		win->state_pose = 1;
		step = 0;
	}
	else
		win->state_pose = 0;
	if (key == KEY_ECHAP)
        exit(53);
	if (!win->victory)
	{
		ft_put_image_to_image(&win->map_img, &win->ground, win->player_pos.x, win->player_pos.y);
		if (key == KEY_A)
		{
			if (win->player_pos.x >= 50
				&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != '1' && win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != 'E')
				win->player_pos.x -= 50;
			else if (win->player_pos.x >= 50
				&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != '1' && nocolectible_is_true(win->map))
				win->player_pos.x -= 50;
			if (step >= 2)
				ft_put_image_to_image(&win->map_img, &win->player_left, win->player_pos.x, win->player_pos.y);
			else
				ft_put_image_to_image(&win->map_img, &win->player_left2, win->player_pos.x, win->player_pos.y);
		}
		else if (key == KEY_D)
		{
			if (win->player_pos.x >= 50
				&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 + 1] != '1' && win->map[win->player_pos.y / 50][win->player_pos.x / 50 + 1] != 'E')
				win->player_pos.x += 50;
			else if (win->player_pos.x >= 50
				&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 + 1] != '1' && nocolectible_is_true(win->map))
				win->player_pos.x += 50;
			if (step >= 2)
				ft_put_image_to_image(&win->map_img, &win->player_right, win->player_pos.x, win->player_pos.y);
			else
				ft_put_image_to_image(&win->map_img, &win->player_right2, win->player_pos.x, win->player_pos.y);
		}
		else if (key == KEY_W)
		{
			if (win->player_pos.y >= 50
				&& win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != '1' && win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != 'E')
				win->player_pos.y -= 50;
			else if (win->player_pos.y >= 50
				&& win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != '1' && nocolectible_is_true(win->map))
				win->player_pos.y -= 50;
			ft_put_image_to_image(&win->map_img, &win->player_up, win->player_pos.x, win->player_pos.y);
		}
		else if (key == KEY_S)
		{
			if (win->player_pos.y >= 50
				&& win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != '1' && win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != 'E')
				win->player_pos.y += 50;
			else if (win->player_pos.y >= 50
				&& win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != '1' && nocolectible_is_true(win->map))
				win->player_pos.y += 50;
			ft_put_image_to_image(&win->map_img, &win->player_down, win->player_pos.x, win->player_pos.y);
		}
		//ft_put_image_to_image(&win->map_img, &win->player_right, win->player_pos.x, win->player_pos.y);
		if (win->map[win->player_pos.y / 50][win->player_pos.x / 50] == 'C')
			win->map[win->player_pos.y / 50][win->player_pos.x / 50] = '0';

		if (nocolectible_is_true(win->map) && !win->victory)
			col = 1;
		if (col == 1 && !win->victory)
		{
			y = -1;
			while(win->map[++y])
			{
				x = -1;
				while (win->map[y][++x])
				{
					if (win->map[y][x] == 'E')
					{
						ft_put_image_to_image(&win->map_img, &win->ground, x * 50, y * 50);
						ft_put_image_to_image(&win->map_img, &win->exit_out, x * 50, y * 50);
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
			ft_camera(win, 1);
	}
	return (0);
}