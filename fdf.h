/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 20:24:21 by dchristo          #+#    #+#             */
/*   Updated: 2016/02/14 14:44:50 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# define WIDTH 2400
# define HEIGHT 1400
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
	struct s_point	*next_line;
}					t_point;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				nbcol;
	int				nbline;
	int				x;
	int				y;
	int				zoom;
	float			scale;
	int				red;
	int				green;
	int				blue;
	int				move;
	int				x_mul;
	int				y_mul;
	int				z_mul;
	int				i;
	struct s_point	*first;
	t_img			img;
}					t_env;

void				malloc_error(void);
void				open_error(void);
void				read_error(void);
void				arg_error(void);
int					draw_all_line(t_point **point, t_env e);
int					loop_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				put_string(t_env *e);

#endif
