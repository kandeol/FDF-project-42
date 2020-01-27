/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:59:27 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/15 16:15:28 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hud_proj(t_mlx *mlx)
{
	if (mlx->map.type == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 200, 20, 0xFFFFFF,
				"Projection isometrique");
	if (mlx->map.type == 2)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 200, 20, 0xFFFFFF,
				"Projection parallele");
	if (mlx->map.type == 3)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 200, 20, 0xFFFFFF,
				"Projection perspective");
}

void	ft_projection(t_mlx *mlx, int key)
{
	if (key == ISO)
		mlx->map.type = 1;
	else if (key == PARA)
		mlx->map.type = 2;
	else
		mlx->map.type = 3;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = (int*)mlx_get_data_addr(mlx->img.img_ptr, &(mlx->img.bpp),
			&(mlx->img.size_line), &mlx->img.endian);
	hud(*mlx);
	ft_draw_map(*mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 20, 0xFFFFFF, "FDF");
	ft_hud_proj(mlx);
}
