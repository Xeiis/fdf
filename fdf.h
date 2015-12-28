/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 20:24:21 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/28 21:39:04 by dchristo         ###   ########.fr       */
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
}					t_point;

typedef struct		s_ptr
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_ptr;

void				malloc_error(void);
void				open_error(void);
void				arg_error(void);

#endif
