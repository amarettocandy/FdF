/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:42:39 by bmarlin           #+#    #+#             */
/*   Updated: 2020/02/23 14:42:39 by bmarlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int i)
{
	if ((i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z') ||
			(i >= 'a' && i <= 'z'))
		return (1);
	return (0);
}