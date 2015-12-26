/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:12:17 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/26 16:15:07 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		in_while(char **tmp, int *boucle, char **line, int i)
{
	tmp[0][i] = '\0';
	*boucle = *boucle + 1;
	ft_strcpy(tmp[1], *line);
	free(*line);
	if ((*line = ft_strnew((*(boucle) + 1) * BUFF_SIZE)) == NULL)
		return (-1);
	ft_strcpy(*line, tmp[1]);
	free(tmp[1]);
	if ((tmp[1] = ft_strnew((*(boucle) + 1) * BUFF_SIZE)) == NULL)
		return (-1);
	ft_strcat(*line, tmp[0]);
	return (0);
}

int		retour(int len, char *buf, char *save, int i)
{
	int		j;

	j = 0;
	if (len == -1)
		return (-1);
	else if (buf[i] == '\n')
	{
		while (buf[++i])
			save[j++] = buf[i];
		save[j] = '\0';
		return (1);
	}
	else
		return (0);
}

int		init(char ***tmp, char **line, char **save)
{
	if ((*tmp = (char **)malloc(sizeof(char *) * 3)) == NULL)
		return (-1);
	if ((*line = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	if (!*save)
		if ((*save = ft_strnew(BUFF_SIZE)) == NULL)
			return (-1);
	ft_strcpy(*line, *save);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char				**tmp;
	static	char		*save;
	int					i;
	int					boucle;

	i = -1;
	boucle = 0;
	if ((init(&tmp, line, &save)) == -1)
		return (-1);
	while (++i < 3)
		if ((tmp[i] = (char *)malloc((sizeof(char) * BUFF_SIZE + 1))) == NULL)
			return (-1);
	while ((i = read(fd, tmp[2], BUFF_SIZE)) > 0)
	{
		tmp[2][i] = '\0';
		i = -1;
		while (tmp[2][++i] && tmp[2][i] != '\n')
			tmp[0][i] = tmp[2][i];
		if ((in_while(tmp, &boucle, line, i)) == -1)
			return (-1);
		if (tmp[2][i] == '\n')
			break ;
	}
	return (retour(i, tmp[2], save, i));
}
