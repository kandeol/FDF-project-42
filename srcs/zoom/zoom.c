/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:20:56 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/16 15:57:57 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scal_in(t_map *map)
{
	if (map->scal < 3.0)
		map->scal += 0.1;
}

void	scal_out(t_map *map)
{
	if (map->scal > 0.5)
		map->scal -= 0.1;
}

void	zoom_in(t_mlx *mlx)
{
	scal_in(&mlx->map);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = (int*)mlx_get_data_addr(mlx->img.img_ptr, &(mlx->img.bpp),
			&(mlx->img.size_line), &mlx->img.endian);
	hud(*mlx);
	ft_draw_map(*mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 20, 0xFFFFFF, "FDF");
}

void	zoom_out(t_mlx *mlx)
{
	scal_out(&mlx->map);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = (int*)mlx_get_data_addr(mlx->img.img_ptr, &(mlx->img.bpp),
			&(mlx->img.size_line), &mlx->img.endian);
	hud(*mlx);
	ft_draw_map(*mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 20, 0xFFFFFF, "FDF");
}
