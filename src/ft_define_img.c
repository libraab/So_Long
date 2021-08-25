/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:54:54 by bledda            #+#    #+#             */
/*   Updated: 2021/08/17 11:32:19 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_define_img(t_main *win)
{
	win->ground.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/ground.xpm",
		&win->ground.width, &win->ground.height);
	win->wall.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/wall.xpm",
		&win->wall.width, &win->wall.height);
	win->player_up.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/player_up.xpm",
		&win->player_up.width, &win->player_up.height);
	win->player_down.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/player_down.xpm",
		&win->player_down.width, &win->player_down.height);
	win->player_left.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/player_left.xpm",
		&win->player_left.width, &win->player_left.height);
	win->player_left2.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/player_left2.xpm",
		&win->player_left2.width, &win->player_left2.height);
	win->player_right.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/player_right.xpm",
		&win->player_right.width, &win->player_right.height);
	win->player_right2.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/player_right2.xpm",
		&win->player_right2.width, &win->player_right2.height);
	win->exit.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/closed_door.xpm",
		&win->exit.width, &win->exit.height);
	win->exit_out.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/open_door.xpm",
		&win->exit_out.width, &win->exit_out.height);
	win->ha.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/gold.xpm",
		&win->ha.width, &win->ha.height);
	win->pig.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/pig.xpm",
		&win->pig.width, &win->pig.height);
}
