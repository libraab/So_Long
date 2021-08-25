/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:08:11 by bledda            #+#    #+#             */
/*   Updated: 2021/08/25 20:32:55 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_valid_ext(char *file)
{
	int i;
	
	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '.' && file[i + 1] == 'b' && file[i + 2] == 'e' && file[i + 3] == 'r' && file[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int ft_valid_chars(t_main *win, int count)
{
	int x;
	int y;
	
	x = 0;
	while(x < count - 1)
	{
		y = 0;
		while(win->map[x][y] != '\0')
		{	
			if (win->map[x][y] != '1' && win->map[x][y] != '0' && win->map[x][y] != 'E' && win->map[x][y] != 'P' && win->map[x][y] != 'C')
				return(0);
			y++;
		}
		x++;
	}
	return(1);
}

int	ft_min_chars(t_main *win)
{
	int x;
	int y;
	int p;
	int e;
	int c;

	y = -1;
	p = 0;
	e = 0;
	c = 0;
	while (win->map[++y])
	{
		x = -1;
		while (win->map[y][++x])
		{
			if (win->map[y][x] == 'P')
				p++;
			else if (win->map[y][x] == 'E')
				e++;
			else if (win->map[y][x] == 'C')
				c++;
		}
	}
	if ((p != 1) || (e == 0) || (c == 0))
		return(0);
	return(1);
}

int	ft_valid_walls(t_main *win, int linelen, int line_nb)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	if ((linelen < 5) || (line_nb < 3) )
		return(0);
	while(x++ < line_nb - 1)
	{
		while(win->map[0][y] != '\0')//upper wall
		{	
			if (win->map[0][y++] != '1')
				return(0);
		}
		if (win->map[x][0] != '1' || win->map[x][linelen - 1] != '1')//side_walls
			return(0);
		y = 0;
		while(win->map[line_nb - 1][y] != '\0')//down wall
		{	
			if (win->map[line_nb - 1][y++] != '1')
				return(0);
		}
	}
	return(1);
}

int	ft_parsing(t_main *win, char *file)
{
	char *line;
	int count;
	int linelen;
	int fd;
	int i;
	(void)win;
	
	count = 0;
	if (!ft_valid_ext(file))
	{
		write(2, "Error!\nWrong extention.\n", 24);
		//exit (EXIT_FAILURE);
		return (0);
	}
	fd =  open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	linelen = -1;
	while (get_next_line(fd, &line) > 0)
	{
		count++;
		if (linelen == -1)
			linelen = ft_strlen(line);
		else if (linelen != (int)ft_strlen(line))
		{
			write(2, "Error!\nNot rectangle.\n", 22);
			//exit (EXIT_FAILURE);
			return (0);
		}
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
		//win->map[i] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
		win->map[i++] = ft_strdup(line);
		free(line);
	}
	//win->map[i] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
	win->map[i] = ft_strdup(line);
	free(line);
	close (fd);
	if (!ft_valid_chars(win, count))
	{
		write(2, "Error!\nWrong character.\n", 24);
		//exit (EXIT_FAILURE);
		return (0);
	}
	if (!ft_valid_walls(win, linelen, count))
	{
		write(2, "Error!\nBreach in wall.\n", 23);
		//exit (EXIT_FAILURE);
		return (0);
	}
	if (!ft_min_chars(win))
	{
		write(2, "Error!\nMissing something.\n", 26);
		//exit (EXIT_FAILURE);
		return (0);
	}
	return (1);
}
