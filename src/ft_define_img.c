/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:54:54 by bledda            #+#    #+#             */
/*   Updated: 2021/09/06 15:39:47 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_define_img(t_main *win)
{
	win->ground.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/ground.xpm", &win->ground.wi, &win->ground.he);
	win->wall.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/wall.xpm", &win->wall.wi, &win->wall.he);
	win->p_up.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/p_up.xpm", &win->p_up.wi, &win->p_up.he);
	win->p_down.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/p_d.xpm", &win->p_down.wi, &win->p_down.he);
	win->p_l.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/p_l.xpm", &win->p_l.wi, &win->p_l.he);
	win->p_l2.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/p_l2.xpm", &win->p_l2.wi, &win->p_l2.he);
	win->p_r.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/p_r.xpm", &win->p_r.wi, &win->p_r.he);
	win->p_r2.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/p_r2.xpm", &win->p_r2.wi, &win->p_r2.he);
	win->exit.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/closed_door.xpm", &win->exit.wi, &win->exit.he);
	win->exit2.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/open_door.xpm", &win->exit2.wi, &win->exit2.he);
	win->ha.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/gold.xpm", &win->ha.wi, &win->ha.he);
	win->pig.img = mlx_xpm_file_to_image(win->mlx_ptr,
			"img/pig.xpm", &win->pig.wi, &win->pig.he);
}

static void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + y * data->line_length + x * (data->bits_per_pixel / 8);
	if (color > 0)
		*(unsigned int *) dst = color;
}

static unsigned int	ft_pixel_get(t_data *data, int x, int y)
{
	return (*(unsigned int *)(data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8))));
}

void	ft_put_img(t_sprite *dest, t_sprite *src, int x, int y)
{
	t_data	img_src;
	t_data	img_dst;
	int		xx;
	int		yy;

	img_src.addr = mlx_get_data_addr(src->img, &img_src.bits_per_pixel,
			&img_src.line_length, &img_src.endian);
	img_dst.addr = mlx_get_data_addr(dest->img, &img_dst.bits_per_pixel,
			&img_dst.line_length, &img_dst.endian);
	yy = 0;
	while (yy < src->he)
	{
		xx = 0;
		while (xx < src->wi)
		{
			ft_pixel_put(&img_dst, xx + x, yy + y,
				ft_pixel_get(&img_src, xx, yy));
			xx++;
		}
		yy++;
	}
}
