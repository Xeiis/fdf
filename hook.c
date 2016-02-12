/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchisto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:37:17 by dchristo          #+#    #+#             */
/*   Updated: 2016/02/12 19:42:55 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				put_string(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF,
		ft_strjoin("Zoom UP (+) : ", ft_itoa(e->zoom)));
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF,
		ft_strjoin("Zoom DOWN (-) : ", ft_itoa(e->zoom)));
	mlx_string_put(e->mlx, e->win, 10, 50, 0xFFFFFF,
		ft_strjoin("Scale UP (*) : ", ft_itoa(e->scale)));
	mlx_string_put(e->mlx, e->win, 10, 70, 0xFFFFFF,
		ft_strjoin("Scale DOWN (/) : ", ft_itoa(e->scale)));
	mlx_string_put(e->mlx, e->win, 10, 90, 0xFFFFFF,
		ft_strjoin("Color RED UP / DOWM (4/7) : ", ft_itoa(e->red)));
	mlx_string_put(e->mlx, e->win, 10, 110, 0xFFFFFF,
		ft_strjoin("Color GREEN UP / DOWN (5/8) : ", ft_itoa(e->green)));
	mlx_string_put(e->mlx, e->win, 10, 130, 0xFFFFFF,
		ft_strjoin("Color BLUE UP / DOWN (6/9) : ", ft_itoa(e->blue)));
	mlx_string_put(e->mlx, e->win, 10, 150, 0xFFFFFF,
		ft_strjoin("Move LEFT (<-) : ", ft_itoa(e->x)));
	mlx_string_put(e->mlx, e->win, 10, 170, 0xFFFFFF,
		ft_strjoin("Move UP (^) : ", ft_itoa(e->y)));
	mlx_string_put(e->mlx, e->win, 10, 190, 0xFFFFFF,
		ft_strjoin("Move RIGHT (->) : ", ft_itoa(e->x)));
	mlx_string_put(e->mlx, e->win, 10, 210, 0xFFFFFF,
		ft_strjoin("Move DOWN (down) : ", ft_itoa(e->y)));
	mlx_string_put(e->mlx, e->win, 10, 230, 0xFFFFFF,
		ft_strjoin("UP / DOWN move (2/1) : ", ft_itoa(e->move)));
}

static void			key_hook_2(int keycode, t_env *e)
{
	if (keycode == 125)
		e->y += e->move;
	if (keycode == 69 && e->zoom <= 500)
		e->zoom += 1;
	if (keycode == 78 && e->zoom > 1)
		e->zoom -= 1;
	if (keycode == 67)
		e->scale += 1;
	if (keycode == 75)
		e->scale -= 1;
	if (keycode == 89 && e->red <= 250)
		e->red += 5;
	if (keycode == 86 && e->red >= 5)
		e->red -= 5;
	if (keycode == 91 && e->green <= 250)
		e->green += 5;
	if (keycode == 87 && e->green >= 5)
		e->green -= 5;
	if (keycode == 92 && e->blue <= 250)
		e->blue += 5;
	if (keycode == 88 && e->blue >= 5)
		e->blue -= 5;
}

int					key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 83 && e->move > 1)
		e->move--;
	if (keycode == 84)
		e->move++;
	if (keycode == 123)
		e->x -= e->move;
	if (keycode == 124)
		e->x += e->move;
	if (keycode == 126)
		e->y -= e->move;
	key_hook_2(keycode, e);
	mlx_destroy_image(e->mlx, e->img.img);
	e->img.img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	draw_all_line(&e->first, *e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	put_string(e);
	return (0);
}
