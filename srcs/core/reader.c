/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:34:52 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/16 15:02:16 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_malloc_tmp(t_map *map)
{
	int		size_h;
	int		i;

	i = 0;
	size_h = map->content_h;
	if (!(map->tmp = malloc(sizeof(t_point) * map->content_h)))
		return (EXIT_FAILURE);
	while (size_h--)
	{
		if (!(map->tmp[i] = malloc(sizeof(t_point) * map->content_w)))
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}

static int		setup_map(t_map *map)
{
	t_var	v;
	int		i;
	int		j;

	i = 0;
	j = 0;
	v.size_w = map->content_w;
	v.size_h = map->content_h;
	ft_malloc_tmp(map);
	while (v.size_h--)
	{
		while (v.size_w--)
		{
			map->tab[i][j].x = ((map->tab[i][j].x - (map->content_w / 2)));
			map->tab[i][j].y = ((map->tab[i][j].y - (map->content_h / 2)));
			map->tab[i][j].z = ((map->tab[i][j].z / (map->z_max - map->z_min
							+ 1)) * ((map->content_w / 8) + 0.5));
			j++;
		}
		v.size_w = map->content_w;
		i++;
		j = 0;
	}
	return (EXIT_SUCCESS);
}

static void		ft_mapping(int i, int *j, char **str, t_map *map)
{
	while (str[*j])
	{
		map->tab[i][*j].x = *j;
		map->tab[i][*j].y = i;
		map->tab[i][*j].z = ft_atoi(str[*j]);
		free(str[*j]);
		*j = *j + 1;
	}
}

int				ft_read(int fd2, char *line, t_map *map)
{
	t_var			v;
	char			**str;

	v.i = 0;
	v.j = 0;
	if (!(map->tab = malloc(sizeof(t_point) * map->content_h)))
		return (EXIT_FAILURE);
	while (get_next_line(fd2, &line) > 0)
	{
		if (!(map->tab[v.i] = malloc(sizeof(t_point) * map->content_w)))
			return (EXIT_FAILURE);
		str = ft_strsplit(line, ' ');
		ft_mapping(v.i, &v.j, str, map);
		v.j = 0;
		v.i++;
		free(str);
		free(line);
		line = NULL;
	}
	setup_map(map);
	return (0);
}
