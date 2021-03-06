/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:06:52 by bmarlin           #+#    #+#             */
/*   Updated: 2020/03/03 12:47:20 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 ||\
	key == 91 || key == 28 || key == 84 || key == 19 ||\
	key == '~' || key == '}' || key == '{' || key == '|' ||\
	key == 87 || key == 23 || key == 86 || key == 21 ||\
	key == 49 || key == 88 || key == 22);
}

void	do_key(int key, t_dot **matrix)
{
	if (key == 24 || key == 69)
		matrix[0][0].scale += 3;
	if (key == 27 || key == 78)
		matrix[0][0].scale -= 3;
	if (key == 91 || key == 28)
		matrix[0][0].z_scale += 1;
	if (key == 84 || key == 19)
		matrix[0][0].z_scale -= 1;
	if (key == '~')
		matrix[0][0].shift_y -= 10;
	if (key == '}')
		matrix[0][0].shift_y += 10;
	if (key == '{')
		matrix[0][0].shift_x -= 10;
	if (key == '|')
		matrix[0][0].shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		matrix[0][0].is_isometric = (matrix[0][0].is_isometric) ? 0 : 1;
	if (key == 86 || key == 21)
		matrix[0][0].angle += 0.05;
	if (key == 88 || key == 22)
		matrix[0][0].angle -= 0.05;
}

int		deal_key(int key, t_dot **matrix)
{
	if (is_key(key))
	{
		mlx_clear_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
		do_key(key, matrix);
		print_menu(matrix[0][0]);
		draw(matrix);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, matrix);
	if (key == '5')
	{
		mlx_destroy_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}
