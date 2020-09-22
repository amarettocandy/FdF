/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:50:28 by bmarlin           #+#    #+#             */
/*   Updated: 2020/02/23 14:50:28 by bmarlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swapi(int *c1, int *c2)
{
	int n;

	n = *c1;
	*c1 = *c2;
	*c2 = n;
}