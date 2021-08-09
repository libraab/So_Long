/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:54:18 by bledda            #+#    #+#             */
/*   Updated: 2021/08/09 19:38:23 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x *
		(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static unsigned int	ft_pixel_get(t_data *data, int x, int y)
{
	return *(unsigned int*)(data->addr + (y * data->line_length + x *
		(data->bits_per_pixel / 8)));
}

void	ft_put_image_to_image(t_sprite *dest, t_sprite *src, int x, int y)
{
	t_data img_src;
	t_data img_dst;
	int	xx;
	int yy;

	img_src.addr = mlx_get_data_addr(src->img, &img_src.bits_per_pixel,
		&img_src.line_length, &img_src.endian);
	img_dst.addr = mlx_get_data_addr(dest->img, &img_dst.bits_per_pixel,
		&img_dst.line_length, &img_dst.endian);
	yy = 0;
	while (yy < dest->height)
	{
		xx = 0;
		while (xx < dest->width)
		{
			ft_pixel_put(&img_dst, xx + x, yy + y,
					ft_pixel_get(&img_src, xx, yy));
			xx++;
		}
		yy++;
	}
}
