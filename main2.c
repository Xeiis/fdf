/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:48:49 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/11 23:03:15 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int					expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int					main(/*int argc, char **argv*/void)
{
	t_img			img;
	t_env			e;

	if (1)
	{
		e.mlx = mlx_init();
		e.width = img.width = 800;
		e.height = img.height = 800;
		img.img = mlx_new_image(e.mlx, img.width, img.height);
		img.data = mlx_get_data_addr(img.img, &img.bpp, &img.size_line,
				&img.endian);
		e.img = img;
		e.win = mlx_new_window(e.mlx, e.width, e.height, "42 | FdF");

/*		draw_line(&e.img, (t_vec2){.x = 300, .y = 400}, (t_vec2){.x = 300, .y = 600}, 0xFFFF00);
		draw_line(&e.img, (t_vec2){.x = 300, .y = 400}, (t_vec2){.x = 500, .y = 400}, 0xFFFF00);
		draw_line(&e.img, (t_vec2){.x = 500, .y = 400}, (t_vec2){.x = 500, .y = 600}, 0xFFFF00);
		draw_line(&e.img, (t_vec2){.x = 500, .y = 600}, (t_vec2){.x = 300, .y = 600}, 0xFFFF00);

		draw_line(&e.img, (t_vec2){.x = 300, .y = 400}, (t_vec2){.x = 400, .y = 300}, 0xFFFF00);
		draw_line(&e.img, (t_vec2){.x = 400, .y = 300}, (t_vec2){.x = 600, .y = 300}, 0xFFFF00);
		draw_line(&e.img, (t_vec2){.x = 600, .y = 300}, (t_vec2){.x = 600, .y = 500}, 0xFFFF00);
		draw_line(&e.img, (t_vec2){.x = 600, .y = 500}, (t_vec2){.x = 500, .y = 600}, 0xFFFF00);
		draw_line(&e.img, (t_vec2){.x = 600, .y = 300}, (t_vec2){.x = 500, .y = 400}, 0xFFFF00);*/

		mlx_put_image_to_window(e.mlx, e.win, e.img.img, 0, 0);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
