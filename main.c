/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 17:55:32 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/27 18:53:43 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

void    my_pixel_put_to_image(unsigned int img_color, char *data, int sizeline, int bpp, int x, int y)
{
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;
	color1 = (img_color & 0xFF0000) >> 16;
	color2 = (img_color & 0xFF00) >> 8;
	color3 = (img_color & 0xFF);
	data[y * sizeline + x * bpp / 8 ] = color1;
	data[y * sizeline + x * bpp / 8 + 1] = color2;
	data[y * sizeline + x * bpp / 8 + 2] = color3;
}
int     main()
{
	void  *mlx_ptr;
	void  *win_ptr;
	void  *img_ptr;
	unsigned int img_color;
	char  *data;
	int   bpp;
	int   sizeline;
	int   endian;
	int   z;
	int   y;

	z = 0;
	y = 0;
	mlx_ptr = mlx_init();
	img_ptr = mlx_new_image(mlx_ptr, 500, 500);
	data = mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endian);
	while (z < 500)
	{
		if (z >= 100 && z <= 400 && y >= 100 && y <= 400)
		{
			if (z % 50 == 0 || y % 50 == 0)
			{
				img_color = mlx_get_color_value(mlx_ptr, 0xFFFFFF);
				my_pixel_put_to_image(img_color, data, sizeline, bpp, z, y);
			}
		}
		z++;
		if (z == 500 && y < 500)
		{
			z = 0;
			y++;
		}
	}
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FDF @42" );
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
  	mlx_loop(mlx_ptr);
}

/*int		main(int ac, char **av)
  {
  void	*connection;
  void	*window;
  if (ac > 1)
  {
  if ((connection = mlx_init()) == NULL)
  {
  ft_putstr("fail");
  return (0);
  }*/
/* on cree une window avec le pointeur de mlx init, on lui donne un x un y et un title */
/*if ((window = mlx_new_window(connection, 1920, 1080, av[1])) == NULL)
  {
  ft_putstr("fail");
  return (0);
  }
  mlx_loop(connection);
  *//*supprime les informations dans la fenetre */
/* mlx_clear_window(connection, window); */
/* detruit la fenetre a faire au moment de l'appuie sur echap */
/* mlx_destroy_window(connection, window); */
/*}
  else
  ft_putstr("fail");
  return(0);
  }*/
