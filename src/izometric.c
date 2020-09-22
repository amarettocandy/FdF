/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   izometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:07:47 by bmarlin           #+#    #+#             */
/*   Updated: 2020/03/03 12:42:22 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}
