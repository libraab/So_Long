/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:35:37 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/07 20:02:03 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_game_over(t_main *win, int x)
{
	t_sprite	game_over;

	game_over.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/win.xpm",
			&game_over.wi, &game_over.he);
	if (x == 0)
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			game_over.img, 0, 0);
		printf("%d\n", ++win->all_steps);
		printf("YOU WIN !!\nWOW SO TALENTED\nI'M IMPRESSED\n");
	}
	win->victory = 1;
	return (0);
}
