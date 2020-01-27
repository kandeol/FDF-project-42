/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:40:28 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/15 16:18:51 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_mlx *mlx, int key)
{
	if (key == ROTRZ)
		put_rot_right_z(&mlx->map);
	else
		put_rot_left_z(&mlx->map);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = (int*)mlx_get_data_addr(mlx->img.img_ptr, &(mlx->img.bpp),
			&(mlx->img.size_line), &mlx->img.endian);
	hud(*mlx);
	ft_draw_map(*mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}

void	rotate_x(t_mlx mlx, int key)
{
	if (key == ROTUX)
		put_rot_up_x(&mlx.map);
	else
		put_rot_down_x(&mlx.map);
	mlx_clear_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int*)mlx_get_data_addr(mlx.img.img_ptr, &(mlx.img.bpp),
			&(mlx.img.size_line), &mlx.img.endian);
	hud(mlx);
	ft_draw_map(mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
}

void	rotate_y(t_mlx mlx, int key)
{
	if (key == ROTLY)
		put_rot_left_y(&mlx.map);
	else
		put_rot_right_y(&mlx.map);
	mlx_clear_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int*)mlx_get_data_addr(mlx.img.img_ptr, &(mlx.img.bpp),
			&(mlx.img.size_line), &mlx.img.endian);
	hud(mlx);
	ft_draw_map(mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
}
