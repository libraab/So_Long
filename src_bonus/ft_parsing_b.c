/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:08:11 by bledda            #+#    #+#             */
/*   Updated: 2021/09/08 21:58:15 by abouhlel         ###   ########.fr       */
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
		write(2, "Error!\nNot rectangle or unwanted \\n at the end.\n", 47);
	if (x == 3)
		write(2, "Error!\nWrong character.\n", 24);
	if (x == 4)
		write(2, "Error!\nBreach in upper wall.\n", 29);
	if (x == 5)
		write(2, "Error!\nWrong number of items.\n", 30);
	if (x == 6)
		write(2, "Error!\nTry with the right ARG number.\n", 38);
	if (x == 7)
		write(2, "Error!\nMap too small.\n", 22);
	if (x == 8)
		write(2, "Error!\nBreach in lower wall.\n", 29);
	if (x == 9)
		write(2, "Error!\nBreach in side wall.\n", 28);
	return (0);
}

void	ft_is_dir(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		write(2, "Error!\nThis is a directory\n", 27);
		exit(EXIT_FAILURE);
	}
}

int	ft_stock_map(t_main *win, char *file, char *line, int count)
{
	int	i;
	int	fd;
	int	ret;

	i = 0;
	ret = 1;
	fd = open(file, O_RDONLY);
	win->map = ft_calloc(sizeof(char *), count + 1);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		win->map[i++] = ft_strdup(line);
		if (!ft_valid_rectangle(win, line))
			return (0);
		free(line);
	}
	close (fd);
	if (!ft_valid_chars(win, count))
		return (ft_errors(3));
	if (!ft_valid_walls(win, win->linelen, count))
		return (0);
	if (!ft_min_items(win))
		return (ft_errors(5));
	return (1);
}

int	ft_parsing(t_main *win, char *file)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	win->linelen = -1;
	if (!ft_valid_ext (file))
		return (ft_errors(0));
	ft_is_dir(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_errors(1));
	while (get_next_line(fd, &line) > 0)
	{
		count++;
		free(line);
	}
	free(line);
	count++;
	close (fd);
	if (!ft_stock_map(win, file, line, count))
		return (0);
	return (1);
}
