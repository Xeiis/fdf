/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 17:55:32 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/26 19:50:26 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <unistd.h>

int		main(int ac, char **av)
{
	void	*connection;
	void	*window;
	if (ac > 1)
	{
		if ((connection = mlx_init()) == NULL)
		{
			ft_putstr("fail");
			return (0);
		}
		/* on cree une window avec le pointeur de mlx init, on lui donne un x un y et un title */
		if ((window = mlx_new_window(connection, 1920, 1080, av[1])) == NULL)
		{
			ft_putstr("fail");
			return (0);
		}
		mlx_pixel_put(connection, window, 0, 0, 0xFFFFFF);
		mlx_pixel_put(connection, window, 0, 1, 0xFFFFFF);
		mlx_pixel_put(connection, window, 0, 2, 0xFFFFFF);
		mlx_pixel_put(connection, window, 0, 3, 0xFFFFFF);
		mlx_pixel_put(connection, window, 1, 0, 0xFFFFFF);
		mlx_pixel_put(connection, window, 2, 0, 0xFFFFFF);
		mlx_pixel_put(connection, window, 3, 0, 0xFFFFFF);
		mlx_pixel_put(connection, window, 1, 1, 0xAFAFAF);
		mlx_pixel_put(connection, window, 1, 2, 0xAFAFAF);
		mlx_pixel_put(connection, window, 2, 1, 0xAFAFAF);
		mlx_pixel_put(connection, window, 2, 2, 0xAFAFAF);
		/* supprime les informations dans la fenetre */
		/* mlx_clear_window(connection, window); */
		/* detruit la fenetre a faire au moment de l'appuie sur echap */
		/* mlx_destroy_window(connection, window); */
	}
	else
		ft_putstr("fail");
	sleep(30);
	return(0);
}
