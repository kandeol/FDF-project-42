/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandeol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:07:27 by kandeol           #+#    #+#             */
/*   Updated: 2018/03/16 15:35:50 by kandeol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_init_varmap(t_mlx *mlx)
{
	mlx->map.scal = 1;
	mlx->map.type = 1;
	mlx->map.z_max = 0;
	mlx->map.z_min = 0;
}

static int		ft_check_ac_av(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (ac != 2)
		return (EXIT_FAILURE);
	while (av[i][j] != '.')
		j++;
	if (av[i][++j] == 'f')
		j++;
	else
		return (EXIT_FAILURE);
	if (av[i][j] == 'd')
		j++;
	else
		return (EXIT_FAILURE);
	if (av[i][j] == 'f')
		j++;
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void		ft_new_window(t_mlx mlx)
{
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int*)mlx_get_data_addr(mlx.img.img_ptr, &(mlx.img.bpp),
			&(mlx.img.size_line), &mlx.img.endian);
	ft_draw_map(mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	hud(mlx);
	mlx_hook(mlx.win_ptr, 2, 0, deal_key, &mlx);
	mlx_hook(mlx.win_ptr, 17, 17, deal_key_redcross, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

int				main(int ac, char **av)
{
	t_mlx			mlx;
	int				fd;
	char			*line;

	line = NULL;
	fd = 0;
	ft_init_varmap(&mlx);
	if (ft_check_ac_av(ac, av))
		return (EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (ft_check_map(av, &fd, &mlx.map))
	{
		write(1, "[ERROR MAP]\n", 12);
		return (EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	ft_read(fd, line, &mlx.map);
	close(fd);
	if ((mlx.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 2560, 1440, av[1]))
			== NULL)
		return (EXIT_FAILURE);
	ft_new_window(mlx);
}
