/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:29:02 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/15 13:39:26 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_free_tab(t_mlx *mlx)
{
	int		size_h;
	int		i;

	size_h = mlx->map.content_h;
	i = 0;
	while (size_h--)
	{
		free(mlx->map.tab[i]);
		i++;
	}
	free(mlx->map.tab);
	return (0);
}

int		ft_free_tmp(t_mlx *mlx)
{
	int		size_h;
	int		i;

	size_h = mlx->map.content_h;
	i = 0;
	while (size_h--)
	{
		free(mlx->map.tmp[i]);
		i++;
	}
	free(mlx->map.tmp);
	return (0);
}
