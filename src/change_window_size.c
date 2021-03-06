/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_window_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:06:37 by bmarlin           #+#    #+#             */
/*   Updated: 2020/03/03 12:48:41 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_win_size(int key, t_dot **matrix)
{
	if ((key == 0 && matrix[0][0].win_y <= 500)
			|| (key == 6 && matrix[0][0].win_x <= 500))
		return (1);
	if ((key == 1 && matrix[0][0].win_y > 1000)
			|| (key == 7 && matrix[0][0].win_x > 2000))
		return (1);
	return (0);
}

void	full_screen(t_dot **matrix)
{
	static int old_x;
	static int old_y;

	if (matrix[0][0].win_x != 2560)
	{
		old_x = matrix[0][0].win_x;
		old_y = matrix[0][0].win_y;
	}
	matrix[0][0].win_x = (matrix[0][0].win_x == 2560) ? old_x : 2560;
	matrix[0][0].win_y = (matrix[0][0].win_y == 1400) ? old_y : 1400;
}

void	change_window_size(int key, t_dot **matrix)
{
	if (check_win_size(key, matrix))
		return ;
	if (key == 6)
		matrix[0][0].win_x -= 100;
	if (key == 7)
		matrix[0][0].win_x += 100;
	if (key == 0)
		matrix[0][0].win_y -= 100;
	if (key == 1)
		matrix[0][0].win_y += 100;
	if (key == 3)
		full_screen(matrix);
}

void	new_window(int key, t_dot **matrix)
{
	change_window_size(key, matrix);
	mlx_destroy_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
	matrix[0][0].mlx_ptr = mlx_init();
	matrix[0][0].win_ptr = mlx_new_window(matrix[0][0].mlx_ptr,
			matrix[0][0].win_x, matrix[0][0].win_y, "FDF");
	matrix[0][0].shift_x = matrix[0][0].win_x / 3;
	matrix[0][0].shift_y = matrix[0][0].win_y / 3;
	draw(matrix);
	mlx_key_hook(matrix[0][0].win_ptr, deal_key, matrix);
	mlx_loop(matrix[0][0].mlx_ptr);
}
