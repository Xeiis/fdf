/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 17:55:32 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/28 21:38:07 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point		*save_point(t_point *point, char *line, int nbline)
{
	char			**array_split;
	t_point			*tmp;
	int				i;

	i = 0;
	array_split = ft_strsplit(line, ' ');
	while(array_split[i] != 0)
	{
		if ((tmp = (t_point*)malloc(sizeof(t_point))) == NULL)
			malloc_error();
		point->x = i;
		point->y = nbline;
		point->z = ft_atoi(array_split[i]);
		point->next = tmp;
		point = point->next;
		i++;
	}
	return (point);
}

static t_point		*read_map(char *str, t_point *point)
{
	int				fd;
	char 			*line;
	int				nbline;

	nbline = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		open_error();
	while(get_next_line(fd, &line) > 0)
	{
		point = save_point(point, line, nbline);
		nbline++;
	}
	return (point);
}

static	t_ptr		init_map(t_ptr ptr)
{
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 1920, 1080, "FDF @42" );
	return (ptr);
}

int					main(int argc, char **argv)
{
	t_ptr ptr;
	t_point *point;

	if (argc == 2)
	{
		if ((point = (t_point*)malloc(sizeof(t_point))) == NULL)
			malloc_error();
		point = read_map(argv[1], point);
		ptr = init_map(ptr);
  		mlx_loop(ptr.mlx_ptr);
	}
	else
		arg_error();
	return (0);
}
