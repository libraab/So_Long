/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:36:13 by abouhlel          #+#    #+#             */
/*   Updated: 2022/03/27 20:13:03 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_valid_ext(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '.' && file[i + 1] == 'b' && file[i + 2] == 'e'
			&& file[i + 3] == 'r' && file[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_valid_chars(t_main *win, int count)
{
	int	y;
	int	x;

	y = 0;
	while (y < count - 1)
	{
		x = 0;
		while (win->map[y][x] != '\0')
		{	
			if (win->map[y][x] != '1' && win->map[y][x] != '0' && win->map[y]
				[x] != 'E' && win->map[y][x] != 'P' && win->map[y][x] != 'C' && win->map[y][x] !='K')
			{
				printf("here \n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_valid_walls(t_main *win, int linelen, int line_nb)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (((linelen < 5) && (line_nb < 3)) || ((linelen < 3) && (line_nb < 5)))
		return (ft_errors(7));
	while (y++ < line_nb - 1)
	{
		while (win->map[0][x] != '\0')
		{	
			if (win->map[0][x++] != '1')
				return (ft_errors(4));
		}
		if (win->map[y][0] != '1' || win->map[y][linelen - 1] != '1')
			return (ft_errors(9));
		x = 0;
		while (win->map[line_nb - 1][x] != '\0')
		{	
			if (win->map[line_nb - 1][x++] != '1')
				return (ft_errors(8));
		}
	}
	return (1);
}

int	ft_min_items(t_main *win)
{
	int	x;
	int	y;
	int	e;

	y = -1;
	e = 0;
	win->my_ha = 0;
	win->one_p = 0;
	while (win->map[++y])
	{
		x = -1;
		while (win->map[y][++x])
		{
			if (win->map[y][x] == 'P')
				win->one_p++;
			else if (win->map[y][x] == 'E')
				e++;
			else if (win->map[y][x] == 'C')
				win->my_ha++;
		}
	}
	if ((win->one_p != 1) || (e == 0) || (win->my_ha == 0))
		return (0);
	return (1);
}

int	ft_valid_rectangle(t_main *win, char *line)
{
	if (win->linelen == -1)
		win->linelen = ft_strlen(line);
	else if (win->linelen != (int)ft_strlen(line))
		return (ft_errors(2));
	return (1);
}
