/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:21:19 by dchristo          #+#    #+#             */
/*   Updated: 2016/02/17 13:36:57 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point					to_2d_iso(int x, int y, int z, t_env e)
{
	t_point p;

	p.x = x * e.x_mul + y * e.y_mul;
	p.y = y * e.z_mul - cos(30 * M_PI / 180) * (z * e.scale) +
		sin(30 * M_PI / 180) * (z * e.scale);
	p.z = 0;
	p.next = NULL;
	p.next_line = NULL;
	return (p);
}

int						which_color(t_point *p)
{
	if (p->z >= 1 || p->next->z >= 1)
	{
		if (p->z >= 30 || p->next->z >= 30)
		{
			if (p->z >= 100 || p->next->z >= 100)
				return (RGB(255, 150, 0));
			return (RGB(255, 255, 255));
		}
		return (RGB(0, 255, 0));
	}
	else
		return (RGB(0, 0, 255));
}

int						which_color_next(t_point *p)
{
	if (p->z >= 1 || p->next_line->z >= 1)
	{
		if (p->z >= 30 || p->next_line->z >= 30)
		{
			if (p->z >= 100 || p->next_line->z >= 100)
				return (RGB(255, 150, 0));
			return (RGB(255, 255, 255));
		}
		return (RGB(0, 255, 0));
	}
	else
		return (RGB(0, 0, 255));
}
