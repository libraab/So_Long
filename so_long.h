/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:50:28 by abouhlel          #+#    #+#             */
/*   Updated: 2021/07/15 15:54:33 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

#define SO_LONG_H

#include "mlx.h"
#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct asma
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		step;
}				bank;

void    ft_background(bank s, void *img, void *img2, int x, int y);

#endif