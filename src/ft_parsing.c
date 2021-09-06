/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:08:11 by bledda            #+#    #+#             */
/*   Updated: 2021/09/06 20:17:39 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_errors(int x)
{
	if (x == 0)
		write(2, "Error!\nWrong extention.\n", 24);
	if (x == 1)
		write(2, "Error!\nFile not properly read.\n", 31);
	if (x == 2)
		write(2, "Error!\nNot rectangle.\n", 22);
	if (x == 3)
		write(2, "Error!\nWrong character.\n", 24);
	if (x == 4)
		write(2, "Error!\nBreach in wall.\n", 23);
	if (x == 5)
		write(2, "Error!\nMissing something.\n", 26);
	return (0);
}

int	ft_parsing(t_main *win, char *file)
{
	char	*line;
	int		count;
	int		linelen;
	int		fd;
	int		i;

	count = 0;
	if (!ft_valid_ext (file))
		return (ft_errors(0));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_errors(1));
	linelen = -1;
	while (get_next_line(fd, &line) > 0)
	{
		count++;
		if (linelen == -1)
			linelen = ft_strlen(line);
		else if (linelen != (int)ft_strlen(line))
			return (ft_errors(2));//prob ne compare pas avec la derniere ligne
		free(line);
	}
	free(line);
	count++;
	close (fd);
	fd = open(file, O_RDONLY);
	win->map = ft_calloc(sizeof(char *), count + 1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		win->map[i++] = ft_strdup(line);
		free(line);
	}
	win->map[i] = ft_strdup(line);
	free(line);
	close (fd);
	if (!ft_valid_chars(win, count))
		return (ft_errors(3));
	if (!ft_valid_walls(win, linelen, count))
		return (ft_errors(4));
	if (!ft_min_items(win))
		return (ft_errors(5));
	return (1);
}
