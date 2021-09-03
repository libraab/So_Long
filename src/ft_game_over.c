/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:35:37 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/03 20:17:40 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_game_over(t_main *win, int x)
{
	t_sprite	game_over;

	game_over.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/win.xpm",
			&game_over.width, &game_over.height);
	if (x == 0)
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			game_over.img, 0, 0);
		printf("YOU WIN !!\nSO TALENTED\nI'M IMPRESSED\n");
	}
	return (0);
}
