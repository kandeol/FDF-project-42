/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:33:49 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/16 15:58:52 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define PI 3.14159265
# define ESCAPE 53
# define ZOOMIN 69
# define ZOOMOUT 78
# define ROTRZ 92
# define ROTLZ 89
# define ROTUX 91
# define ROTDX 84
# define ROTRY 88
# define ROTLY 86
# define TRANS_R 124
# define TRANS_L 123
# define TRANS_U 126
# define TRANS_D 125
# define ISO 18
# define PARA 19
# define PERS 20
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1440

typedef struct	s_var
{
	int			i;
	int			j;
	int			size_w;
	int			size_h;
	float		r;
	float		val;
	int			flag;
}				t_var;

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct	s_delta_p
{
	float		dx;
	float		dy;
	float		dz;
	float		ndx;
	float		ndy;
	float		ndz;
}				t_dp;

typedef	struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef	struct	s_map
{
	t_point		**tab;
	t_point		**tmp;
	int			type;
	int			content_w;
	int			content_h;
	float		z_max;
	float		z_min;
	float		scal;
	float		r;
	int			coef;
}				t_map;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_map		map;
}				t_mlx;

typedef struct	s_bres
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_bres;

int				ft_read(int fd, char *line, t_map *map);
int				ft_draw_map(t_mlx mlx);
void			put_rot_right_z(t_map *map);
void			put_rot_left_z(t_map *map);
void			put_rot_up_x(t_map *map);
void			put_rot_down_x(t_map *map);
void			put_rot_right_y(t_map *map);
void			put_rot_left_y(t_map *map);
void			put_trans_right(t_map *map);
void			put_trans_left(t_map *map);
void			put_trans_up(t_map *map);
void			put_trans_down(t_map *map);
t_point			ft_pers_map(t_point tmp, t_map *map);
t_point			ft_iso_map(t_point tmp, t_map *map);
t_point			ft_para_map(t_point tmp, t_map *map);
float			ft_norm(float nb);
void			scal_in(t_map *map);
void			scal_out(t_map *map);
void			zoom_in(t_mlx *mlx);
void			zoom_out(t_mlx *mlx);
void			rotate_x(t_mlx mlx, int key);
void			rotate_z(t_mlx *mlx, int key);
void			rotate_y(t_mlx mlx, int key);
void			trans_h(t_mlx mlx, int key);
void			trans_v(t_mlx mlx, int key);
void			ft_projection(t_mlx *mlx, int key);
void			ft_init_tmp(t_map *map);
void			hud(t_mlx mlx);
int				ft_free_tab(t_mlx *mlx);
int				ft_free_tmp(t_mlx *mlx);
int				ft_check_map(char **av, int *fd, t_map *map);
void			ft_init_var(t_var *v, t_map *map);
int				deal_key(int key, t_mlx *mlx);
int				deal_key_redcross(t_mlx *mlx);

#endif
