/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:08:03 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/16 15:33:09 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_delta_z(float z, t_map *map)
{
	if (z > map->z_max)
		map->z_max = z;
	if (z < map->z_min)
		map->z_min = z;
}

static int		ft_check_digit(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != ',')
	{
		if (s[i] == '-')
			i++;
		if ((ft_isdigit(s[i])) == 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int		ft_check_core(t_var *v, char **str, t_map *map)
{
	while (str[v->j])
	{
		if ((ft_check_digit(str[v->j])) == 1)
			return (EXIT_FAILURE);
		map->content_w++;
		ft_delta_z(ft_atoi(str[v->j]), map);
		free(str[v->j]);
		v->j++;
	}
	if (v->flag == 0)
	{
		v->size_w = map->content_w;
		v->flag = 1;
	}
	if (v->size_w != map->content_w || v->size_w == 0)
		return (EXIT_FAILURE);
	return (0);
}

int				ft_check_map(char **av, int *fd, t_map *map)
{
	t_var	v;
	char	**str;
	char	*line;

	v.j = 0;
	v.flag = 0;
	line = NULL;
	while (get_next_line(*fd, &line) > 0)
	{
		map->content_w = 0;
		str = ft_strsplit(line, ' ');
		if (ft_check_core(&v, str, map))
			return (EXIT_FAILURE);
		v.j = 0;
		free(str);
		free(line);
		map->content_h++;
	}
	return (EXIT_SUCCESS);
}
