/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 17:55:32 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/19 13:24:04 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point		*save_point(t_point **point, char *line, int nbline)
{
	char			**array_split;
	t_point			*p;
	int				i;

	i = 0;
	p = *point;
	array_split = ft_strsplit(line, ' ');
	while(array_split[i] != 0)
	{
		if ((p->next = (t_point*)malloc(sizeof(t_point))) == NULL)
			malloc_error();
		
		p->x = i;
		p->y = nbline;
		p->z = ft_atoi(array_split[i]);
		p = p->next;
		i++;
	}
	p->next = NULL;
	return (p);
}

static int			read_map(char *str, t_point **point)
{
	int				fd;
	char 			*line;
	int				nbline;
	t_point 		*p;
	p = *point;
	nbline = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		open_error();
	while(get_next_line(fd, &line) > 0)
	{
		p = save_point(&p, line, nbline);
		nbline++;
	}
	return (1);
}

static	t_ptr		init_map(t_ptr ptr)
{
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 1920, 1080, "FDF @42" );
	return (ptr);
}

/*void	write_point(t_point **point)
{
	t_point *p;
	int save;

	p = *point;
	save = p->y;
	while (p->next != NULL)
	{
		if (p->y != save)
		{
			printf("\n");
			save = p->y;
		}
		printf("%d ", p->z);
		p = p->next;
	}
}*/


int					main(int argc, char **argv)
{
	t_ptr ptr;
	t_point *point;

	if (argc == 2)
	{
		if ((point = (t_point *)malloc(sizeof(t_point))) == NULL)
			malloc_error();
		read_map(argv[1], &point);
		ptr = init_map(ptr);
  		mlx_loop(ptr.mlx_ptr);
	}
	else
		arg_error();
	return (0);
}
