/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:07:28 by bmarlin           #+#    #+#             */
/*   Updated: 2020/03/03 12:47:15 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"

typedef struct
{
	float		x;
	float		y;
	float		z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_dot;

t_dot			**read_map(char *file_name);
void			isometric(t_dot *dot, double angle);
void			draw(t_dot **matrix);
int				deal_key(int key, t_dot **matrix);
void			set_param(t_dot *a, t_dot *b, t_dot *param);
void			print_menu(t_dot param);
void			ft_error(char *msg);
void			new_window(int key, t_dot **matrix);

#endif
