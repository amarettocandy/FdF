/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:45:35 by bmarlin           #+#    #+#             */
/*   Updated: 2020/02/23 14:45:35 by bmarlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *restrict dst, const void *restrict src, \
		int c, size_t n)
{
	while (n)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		if (*(unsigned char*)src == (unsigned char)c)
			return (++dst);
		dst++;
		src++;
		n--;
	}
	return (NULL);
}
