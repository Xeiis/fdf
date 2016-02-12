/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 21:23:08 by dchristo          #+#    #+#             */
/*   Updated: 2016/02/12 19:29:11 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	arg_error(void)
{
	ft_putstr_fd("Nombre d'argument invalide\n", 2);
	exit(1);
}

void	malloc_error(void)
{
	ft_putstr_fd("Malloc erreur\n", 2);
	exit(1);
}

void	open_error(void)
{
	ft_putstr_fd("Erreur lors de l'ouverture du fichier\n", 2);
	exit(1);
}

void	read_error(void)
{
	ft_putstr_fd("Erreur lors de la lecture du fichier\n", 2);
	exit(1);
}
