/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 21:23:08 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/04 15:50:43 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	arg_error()
{
	ft_putstr_fd("Nombre d'argument invalide\n", 2);
	exit(1);
}

void	malloc_error()
{
	ft_putstr_fd("Malloc error\n", 2);
	exit(1);
}

void	open_error()
{
	ft_putstr_fd("Erreur lors de l'ouverture du fichier\n", 2);
	exit(1);
}

