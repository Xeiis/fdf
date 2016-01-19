/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 20:24:21 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/19 14:25:46 by dchristo         ###   ########.fr       */
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

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
	struct s_point	*next_line;
}					t_point;

typedef struc		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				width;
	int				height;
}					t_img

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
}					t_env;

void				malloc_error(void);
void				open_error(void);
void				arg_error(void);

#endif
