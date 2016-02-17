/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 17:55:32 by dchristo          #+#    #+#             */
/*   Updated: 2016/02/17 13:32:31 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point		*save_point(t_point **point, char *line, t_env *env)
{
	char			**array_split;
	t_point			*p;

	env->nbcol = 0;
	p = *point;
	array_split = ft_strsplit(line, ' ');
	while (array_split[env->nbcol] != 0)
	{
		p->x = env->nbcol;
		p->y = env->nbline;
		p->z = ft_atoi(array_split[env->nbcol]);
		env->nbcol++;
		if ((p->next = (t_point*)malloc(sizeof(t_point))) == NULL)
			malloc_error();
		p = p->next;
	}
	p->next = NULL;
	return (p);
}

static int			read_map(char *str, t_point **point, t_env *env)
{
	int				fd;
	int				ret;
	char			*line;
	t_point			*p;

	p = *point;
	env->nbline = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		open_error();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		p = save_point(&p, line, env);
		env->nbline++;
	}
	if (ret == -1)
		read_error();
	return (1);
}

static	t_env		init_map(t_env ptr, char *name)
{
	ptr.img.width = 2400;
	ptr.img.height = 1400;
	ptr.i = 1;
	ptr.x = 0;
	ptr.y = 0;
	ptr.x_mul = 5;
	ptr.y_mul = 1;
	ptr.z_mul = 5;
	ptr.zoom = 1;
	ptr.scale = 1;
	ptr.red = 0;
	ptr.green = 0;
	ptr.blue = 255;
	ptr.move = 1;
	ptr.mlx = mlx_init();
	ptr.img.img = mlx_new_image(ptr.mlx, ptr.img.width, ptr.img.height);
	ptr.img.data = mlx_get_data_addr(ptr.img.img, &ptr.img.bpp,
		&ptr.img.sizeline, &ptr.img.endian);
	ptr.win = mlx_new_window(ptr.mlx, ptr.img.width, ptr.img.height, name);
	return (ptr);
}

static int			init_s_point(t_point **point, t_env e)
{
	t_point *p;
	t_point *p2;

	(void)e;
	p = *point;
	while (p->next != NULL)
	{
		p2 = *point;
		while (p2->next != NULL)
		{
			if ((p->x == p2->x && p->y == p2->y - 1))
			{
				p->next_line = p2;
				break ;
			}
			else
				p->next_line = NULL;
			p2 = p2->next;
		}
		p = p->next;
	}
	return (0);
}

int					main(int argc, char **argv)
{
	t_env env;

	if (argc == 2)
	{
		if ((env.first = (t_point *)malloc(sizeof(t_point))) == NULL)
			malloc_error();
		read_map(argv[1], &env.first, &env);
		init_s_point(&env.first, env);
		env = init_map(env, argv[1]);
		draw_all_line(&env.first, env);
		mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
		put_string(&env);
		mlx_hook(env.win, 2, 1, key_hook, &env);
		mlx_loop(env.mlx);
	}
	else
		arg_error();
	return (0);
}
