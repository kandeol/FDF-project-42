/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:23:17 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/09 13:20:00 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	hud2(t_mlx mlx)
{
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 290, 0xFFFFFF, "2 : X bas");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 310, 0xFFFFFF, "8 : X haut");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 330, 0xFFFFFF,
			"7 : Z gauche");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 350, 0xFFFFFF,
			"9 : Z droite");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 380, 0xFFFFFF,
			"TRANSLATION");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 410, 0xFFFFFF,
			"fleche droite : droite ");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 430, 0xFFFFFF,
			"fleche gauche : gauche");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 450, 0xFFFFFF,
			"fleche haut : haut");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 470, 0xFFFFFF,
			"fleche bas : bas");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 500, 0xFFFFFF, "ZOOM");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 530, 0xFFFFFF, "+ : zoom+");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 550, 0xFFFFFF, "- : zoom-");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 700, 0xFFFFFF,
			"esc : QUITTER");
}

void		hud(t_mlx mlx)
{
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 20, 0xFFFFFF, "FDF");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 60, 0xFFFFFF, "Commandes :");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 120, 0xFFFFFF, "PROJECTION");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 150, 0xFFFFFF,
			"1/! : Isometrique");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 170, 0xFFFFFF,
			"2/@ : Parallele");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 190, 0xFFFFFF,
			"3/# : Perspective");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 220, 0xFFFFFF, "ROTATION");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 250, 0xFFFFFF,
			"6 : Y droite");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 2000, 270, 0xFFFFFF,
			"4 : Y gauche");
	hud2(mlx);
}
