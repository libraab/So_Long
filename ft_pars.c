/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:54:14 by abouhlel          #+#    #+#             */
/*   Updated: 2021/08/09 17:05:29 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

/*
    ouvrir mon fichier .ber
    verifier si elle est valide
    lire le contenu (lire ligne par ligne)
    copier le contenue dans **map(t_bank)
    
    Open dans fd av[1]
    si fd egal pas -1
        count++ temps que GNL > 0
    calloc **map de la taille de count + 1
    close fd
    open fd
    strdup de line de GNL temps que gnl > 0
    close fd
*/
void    ft_pars(t_bank *a, char **av)
{
    int fd;
    fd = open(av[1], O_RDONLY);
}