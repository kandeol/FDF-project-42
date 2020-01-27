/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_proj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:27:35 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/15 16:12:39 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		ft_pers_map(t_point tmp, t_map *map)
{
	t_point			new;
	float			w;
	float			size;

	size = (WIN_WIDTH / (hypot(map->content_w, map->content_h) * 1.5));
	w = 1 - (tmp.z / map->content_w) + 0.01;
	new.x = tmp.x / w;
	new.y = tmp.y / w;
	new.x *= size;
	new.y *= size;
	new.x *= map->scal;
	new.y *= map->scal;
	new.x += WIN_WIDTH * 0.5;
	new.y += WIN_HEIGHT * 0.5;
	return (new);
}

t_point		ft_iso_map(t_point tmp, t_map *map)
{
	t_point			new;
	float			size;

	new.x = tmp.x - tmp.y;
	new.y = ((tmp.x * 0.4) + tmp.y - (tmp.z));
	size = (WIN_WIDTH / (hypot(map->content_h, map->content_w) * 1.8));
	new.x *= size;
	new.y *= size;
	new.z *= size;
	new.x *= map->scal;
	new.y *= map->scal;
	new.x += WIN_WIDTH * 0.5;
	new.y += WIN_HEIGHT * 0.5;
	return (new);
}

t_point		ft_para_map(t_point tmp, t_map *map)
{
	t_point			new;
	float			size;

	new.x = tmp.x;
	new.y = tmp.y;
	size = (WIN_WIDTH / (hypot(map->content_w, map->content_h) * 1.5));
	new.x *= size;
	new.y *= size;
	new.x *= map->scal;
	new.y *= map->scal;
	new.x += WIN_WIDTH * 0.5;
	new.y += WIN_HEIGHT * 0.5;
	return (new);
}
