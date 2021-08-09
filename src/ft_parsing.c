/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:08:11 by bledda            #+#    #+#             */
/*   Updated: 2021/08/09 19:45:47 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_parsing(t_main *win, char *file)
{
	int fd;
	int count;
	char *line;
	int i;

	count = 0;
	fd =  open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		count++;
		free(line);
	}
	count++;
	close (fd);
	fd = open(file, O_RDONLY);
	win->map = ft_calloc(sizeof(char *), count + 1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		win->map[i] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
		win->map[i++] = ft_strdup(line);
		free(line);
	}
	win->map[i] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
	win->map[i] = ft_strdup(line);
	close (fd);
	win->map_img.width = ft_strlen(win->map[i]) * 50;
	win->map_img.height = i * 50;
	return (1);
}
