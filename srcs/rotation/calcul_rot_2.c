/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_rot_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:11:30 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/15 17:23:40 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_rot_left_y(t_map *map)
{
	t_var	v;

	ft_init_var(&v, map);
	while (v.size_h--)
	{
		while (v.size_w--)
		{
			map->tab[v.i][v.j].x = (map->tab[v.i][v.j].x * cos(v.r * v.val))
				+ (map->tab[v.i][v.j].z * -sin(v.r * v.val));
			map->tab[v.i][v.j].z = (map->tab[v.i][v.j].x * sin(v.r * v.val))
				+ (map->tab[v.i][v.j].z * cos(v.r * v.val));
			v.j++;
		}
		v.size_w = map->content_w;
		v.i++;
		v.j = 0;
	}
}

void	put_rot_right_y(t_map *map)
{
	t_var	v;

	ft_init_var(&v, map);
	while (v.size_h--)
	{
		while (v.size_w--)
		{
			map->tab[v.i][v.j].x = (map->tab[v.i][v.j].x * cos(v.r * v.val))
				+ (map->tab[v.i][v.j].z * sin(v.r * v.val));
			map->tab[v.i][v.j].z = (map->tab[v.i][v.j].x * -sin(v.r * v.val))
				+ (map->tab[v.i][v.j].z * cos(v.r * v.val));
			v.j++;
		}
		v.size_w = map->content_w;
		v.i++;
		v.j = 0;
	}
}
