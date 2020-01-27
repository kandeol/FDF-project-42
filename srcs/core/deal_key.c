/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:00:48 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/15 19:03:22 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key_redcross(t_mlx *mlx)
{
	ft_free_tab(mlx);
	ft_free_tmp(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == ESCAPE)
	{
		ft_free_tab(mlx);
		ft_free_tmp(mlx);
		exit(EXIT_SUCCESS);
	}
	if (key == ZOOMIN)
		zoom_in(mlx);
	if (key == ZOOMOUT)
		zoom_out(mlx);
	if (key == ISO || key == PARA || key == PERS)
		ft_projection(mlx, key);
	if (key == ROTRZ || key == ROTLZ)
		rotate_z(mlx, key);
	if (key == ROTUX || key == ROTDX)
		rotate_x(*mlx, key);
	if (key == ROTLY || key == ROTRY)
		rotate_y(*mlx, key);
	if (key == TRANS_R || key == TRANS_L)
		trans_h(*mlx, key);
	if (key == TRANS_U || key == TRANS_D)
		trans_v(*mlx, key);
	return (0);
}
