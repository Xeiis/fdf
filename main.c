/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 17:55:32 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/19 14:34:31 by dchristo         ###   ########.fr       */
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
	ptr.img.width = 1920;
	ptr.img.height = 1080;
	ptr.mlx_ptr = mlx_init();
	ptr.img.img = mlx_new_image(ptr.mlx, ptr.img.width, ptr.img.height);
	ptr.img.data = mlx_get_data_addr(ptr.img.img, &ptr.img.bpp, &ptr.img.sizeline, &ptr.img.endian);
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, ptr.img.width, ptr.img.height, "FDF @42" );
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
int					expose_hook(t_env *env)
{
	mlx_put_image_to_window(env->mlx, end->win, env->img.img, 0, 0);
	return (0);
}

int					main(int argc, char **argv)
{
	t_env env;
	t_point *point;

	if (argc == 2)
	{
		if ((point = (t_point *)malloc(sizeof(t_point))) == NULL)
			malloc_error();
		read_map(argv[1], &point);
		env = init_map(env);
		// on ecrit des lignes;
		// mon code pour tracer les lignes lues
		mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
		mlx_expose_hook(env.win, expose_hook, &env);
  		mlx_loop(ptr.mlx_ptr);
	}
	else
		arg_error();
	return (0);
}
