/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:47:54 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/25 19:32:37 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int    ft_game_over(t_main *win, int x)
{
    t_sprite game_over;
    
    game_over.img = mlx_xpm_file_to_image(win->mlx_ptr, "img/win.xpm",
		&game_over.width, &game_over.height);
    if (x == 0)
        ft_put_image_to_image(&win->map_img, &game_over, 0, 0);
    return(0);
}