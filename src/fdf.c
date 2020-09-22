/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:07:19 by bmarlin           #+#    #+#             */
/*   Updated: 2020/03/03 12:40:23 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_close(void)
{
	exit(0);
}

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr =\
	mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
}

int		main(int argc, char **argv)
{
	t_dot	**matrix;
	int		fd;

	fd = open(argv[1], O_DIRECTORY);
	if (argc != 2 || fd != -1)
	{
		close(fd);
		ft_error("usage: ./fdf map.fdf");
	}
	close(fd);
	matrix = read_map(*++argv);
	set_default(&matrix[0][0]);
	draw(matrix);
	mlx_key_hook(matrix[0][0].win_ptr, deal_key, matrix);
	mlx_hook(matrix[0][0].win_ptr, 17, 0, &ft_close, 0);
	mlx_loop(matrix[0][0].mlx_ptr);
}
