/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:57:45 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/15 17:17:26 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_var(t_var *v, t_map *map)
{
	v->size_w = map->content_w;
	v->size_h = map->content_h;
	v->i = 0;
	v->j = 0;
	v->r = 1.0;
	v->val = PI / 180;
}

void	put_rot_right_z(t_map *map)
{
	t_var		v;

	ft_init_var(&v, map);
	while (v.size_h--)
	{
		while (v.size_w--)
		{
			map->tab[v.i][v.j].x = ((map->tab[v.i][v.j].x * cos(v.r * v.val))
					+ (map->tab[v.i][v.j].y * -sin(v.r * v.val)));
			map->tab[v.i][v.j].y = ((map->tab[v.i][v.j].x * sin(v.r * v.val))
					+ (map->tab[v.i][v.j].y * cos(v.r * v.val)));
			v.j++;
		}
		v.size_w = map->content_w;
		v.i++;
		v.j = 0;
	}
}

void	put_rot_left_z(t_map *map)
{
	t_var	v;

	ft_init_var(&v, map);
	while (v.size_h--)
	{
		while (v.size_w--)
		{
			map->tab[v.i][v.j].x = ((map->tab[v.i][v.j].x * cos(v.r * v.val))
					+ (map->tab[v.i][v.j].y * sin(v.r * v.val)));
			map->tab[v.i][v.j].y = ((map->tab[v.i][v.j].x * -sin(v.r * v.val))
					+ (map->tab[v.i][v.j].y * cos(v.r * v.val)));
			v.j++;
		}
		v.size_w = map->content_w;
		v.i++;
		v.j = 0;
	}
}

void	put_rot_up_x(t_map *map)
{
	t_var	v;

	ft_init_var(&v, map);
	while (v.size_h--)
	{
		while (v.size_w--)
		{
			map->tab[v.i][v.j].y = (map->tab[v.i][v.j].y * cos(v.r * v.val))
				+ (map->tab[v.i][v.j].z * -sin(v.r * v.val));
			map->tab[v.i][v.j].z = (((map->tab[v.i][v.j].y * sin(v.r * v.val))
						+ (map->tab[v.i][v.j].z * cos(v.r * v.val))));
			v.j++;
		}
		v.size_w = map->content_w;
		v.i++;
		v.j = 0;
	}
}

void	put_rot_down_x(t_map *map)
{
	t_var	v;

	ft_init_var(&v, map);
	while (v.size_h--)
	{
		while (v.size_w--)
		{
			map->tab[v.i][v.j].y = (map->tab[v.i][v.j].y * cos(v.r * v.val))
				+ (map->tab[v.i][v.j].z * sin(v.r * v.val));
			map->tab[v.i][v.j].z = (((map->tab[v.i][v.j].y * -sin(v.r * v.val))
						+ (map->tab[v.i][v.j].z * cos(v.r * v.val))));
			v.j++;
		}
		v.size_w = map->content_w;
		v.i++;
		v.j = 0;
	}
}
