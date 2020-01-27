/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:42:44 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/15 17:25:01 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trans_h(t_mlx mlx, int key)
{
	if (key == TRANS_R)
		put_trans_right(&mlx.map);
	else
		put_trans_left(&mlx.map);
	mlx_clear_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int*)mlx_get_data_addr(mlx.img.img_ptr, &(mlx.img.bpp),
			&(mlx.img.size_line), &mlx.img.endian);
	hud(mlx);
	ft_draw_map(mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 20, 20, 0xFFFFFF, "FDF");
}

void	trans_v(t_mlx mlx, int key)
{
	if (key == TRANS_U)
		put_trans_up(&mlx.map);
	else
		put_trans_down(&mlx.map);
	mlx_clear_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int*)mlx_get_data_addr(mlx.img.img_ptr, &(mlx.img.bpp),
			&(mlx.img.size_line), &mlx.img.endian);
	hud(mlx);
	ft_draw_map(mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 20, 20, 0xFFFFFF, "FDF");
}
