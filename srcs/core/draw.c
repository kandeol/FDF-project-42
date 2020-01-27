/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:41:43 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/16 15:40:34 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			ft_type_map(t_point tmp, t_map *map)
{
	t_point		new;

	if (map->type == 1)
		new = ft_iso_map(tmp, map);
	else if (map->type == 2)
		new = ft_para_map(tmp, map);
	else if (map->type == 3)
		new = ft_pers_map(tmp, map);
	return (new);
}

static void		ft_map_tmp(t_map *map)
{
	t_var	v;

	v.size_w = map->content_w;
	v.size_h = map->content_h;
	v.i = 0;
	v.j = 0;
	while (v.size_h--)
	{
		while (v.size_w--)
		{
			map->tmp[v.i][v.j] = ft_type_map(map->tab[v.i][v.j], map);
			v.j++;
		}
		v.size_w = map->content_w;
		v.i++;
		v.j = 0;
	}
}

static void		ft_init_bres(t_bres *bres, t_point p1, t_point p2)
{
	bres->dx = ft_abs((int)p2.x - (int)p1.x);
	bres->dy = ft_abs((int)p2.y - (int)p1.y);
	bres->sx = (int)p1.x < (int)p2.x ? 1 : -1;
	bres->sy = (int)p1.y < (int)p2.y ? 1 : -1;
	bres->err = (bres->dx > bres->dy ? bres->dx : -bres->dy) / 2;
}

static void		ft_draw_seg(t_point p1, t_point p2, t_mlx *mlx)
{
	t_bres	bres;

	ft_init_bres(&bres, p1, p2);
	while (1)
	{
		if (((int)p1.y < WIN_HEIGHT) && ((int)p1.y > 0)
				&& ((int)p1.x < WIN_WIDTH) && ((int)p1.x > 0))
			mlx->img.data[((int)p1.y * (WIN_WIDTH) + (int)p1.x)] = 0xADADAD;
		if ((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y)
			break ;
		bres.e2 = bres.err;
		if (bres.e2 > -bres.dx)
		{
			bres.err = bres.err - bres.dy;
			p1.x = (int)p1.x + bres.sx;
		}
		if (bres.e2 < bres.dy)
		{
			bres.err = bres.err + bres.dx;
			p1.y = (int)p1.y + bres.sy;
		}
	}
}

int				ft_draw_map(t_mlx mlx)
{
	t_var		v;
	int			i;
	int			j;

	i = 0;
	j = 0;
	ft_map_tmp(&mlx.map);
	v.size_h = mlx.map.content_h;
	v.size_w = (mlx.map.content_w) - 1;
	while (v.size_h--)
	{
		while (v.size_w--)
		{
			ft_draw_seg(mlx.map.tmp[i][j], mlx.map.tmp[i][j + 1], &mlx);
			if (v.size_h > 0)
				ft_draw_seg(mlx.map.tmp[i][j], mlx.map.tmp[i + 1][j], &mlx);
			j++;
		}
		v.size_w = (mlx.map.content_w) - 1;
		if (v.size_h > 0)
			ft_draw_seg(mlx.map.tmp[i][j], mlx.map.tmp[i + 1][j], &mlx);
		i++;
		j = 0;
	}
	return (0);
}
