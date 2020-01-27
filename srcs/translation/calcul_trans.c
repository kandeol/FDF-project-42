/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:00:24 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/09 13:38:37 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_trans_right(t_map *map)
{
	int		size_w;
	int		size_h;
	int		i;
	int		j;

	size_w = map->content_w;
	size_h = map->content_h;
	i = 0;
	j = 0;
	while (size_h--)
	{
		while (size_w--)
		{
			map->tab[i][j].x -= 1;
			j++;
		}
		size_w = map->content_w;
		i++;
		j = 0;
	}
}

void	put_trans_left(t_map *map)
{
	int		size_w;
	int		size_h;
	int		i;
	int		j;

	size_w = map->content_w;
	size_h = map->content_h;
	i = 0;
	j = 0;
	while (size_h--)
	{
		while (size_w--)
		{
			map->tab[i][j].x += 1;
			j++;
		}
		size_w = map->content_w;
		i++;
		j = 0;
	}
}

void	put_trans_up(t_map *map)
{
	int		size_w;
	int		size_h;
	int		i;
	int		j;

	size_w = map->content_w;
	size_h = map->content_h;
	i = 0;
	j = 0;
	while (size_h--)
	{
		while (size_w--)
		{
			map->tab[i][j].y += 1;
			j++;
		}
		size_w = map->content_w;
		i++;
		j = 0;
	}
}

void	put_trans_down(t_map *map)
{
	int		size_w;
	int		size_h;
	int		i;
	int		j;

	size_w = map->content_w;
	size_h = map->content_h;
	i = 0;
	j = 0;
	while (size_h--)
	{
		while (size_w--)
		{
			map->tab[i][j].y -= 1;
			j++;
		}
		size_w = map->content_w;
		i++;
		j = 0;
	}
}
