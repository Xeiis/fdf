/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:36:25 by ldubos            #+#    #+#             */
/*   Updated: 2016/02/17 13:37:16 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void				put_pixel(t_img *img, t_point p, int color)
{
	char			*pixel;

	if ((p.x < img->width && p.y < img->height) && (p.x >= 0 && p.y >= 0))
	{
		pixel = img->data + p.y * img->sizeline + (img->bpp / 8) * p.x;
		pixel[2] = (char)(color >> 16);
		pixel[1] = (char)(color >> 8);
		pixel[0] = (char)(color);
	}
}

static void				draw_line_pta(t_img *img, t_point a, t_point b, int c)
{
	t_point			p;

	p.x = a.x;
	while (p.x < b.x)
	{
		p.y = a.y + ((b.y - a.y) * (p.x - a.x)) / (b.x - a.x);
		put_pixel(img, p, c);
		++p.x;
	}
}

static void				draw_line_ptb(t_img *img, t_point a, t_point b, int c)
{
	t_point			p;

	p.y = a.y;
	while (p.y < b.y)
	{
		p.x = a.x + ((b.x - a.x) * (p.y - a.y)) / (b.y - a.y);
		put_pixel(img, p, c);
		++p.y;
	}
}

static void				draw_line(t_env e, t_point p1, t_point p2, int color)
{
	t_point			p;

	p1.x = ((p1.x + e.x) * e.zoom);
	p1.y = ((p1.y + e.y) * e.zoom);
	p2.x = ((p2.x + e.x) * e.zoom);
	p2.y = ((p2.y + e.y) * e.zoom);
	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	p.x < 0 ? p.x = -p.x : p.x;
	p.y < 0 ? p.y = -p.y : p.y;
	if (p.x > p.y)
	{
		if (p1.x <= p2.x)
			draw_line_pta(&e.img, p1, p2, color);
		else
			draw_line_pta(&e.img, p2, p1, color);
	}
	else
	{
		if (p1.y < p2.y)
			draw_line_ptb(&e.img, p1, p2, color);
		else
			draw_line_ptb(&e.img, p2, p1, color);
	}
}

int						draw_all_line(t_point **point, t_env e)
{
	t_point *p;

	p = *point;
	while (p->next != NULL)
	{
		if (p->y == p->next->y)
			draw_line(e, to_2d_iso(p->x, p->y, p->z, e),
			to_2d_iso(p->next->x, p->next->y, p->next->z, e), which_color(p));
		if (p->next_line != NULL)
			draw_line(e, to_2d_iso(p->x, p->y, p->z, e),
			to_2d_iso(p->next_line->x, p->next_line->y, p->next_line->z, e),
			which_color_next(p));
		p = p->next;
	}
	return (1);
}
