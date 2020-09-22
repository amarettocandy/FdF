/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:44:28 by bmarlin           #+#    #+#             */
/*   Updated: 2020/02/23 14:44:28 by bmarlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	convert(int i)
{
	char *nums;

	nums = "0123456789abcdef";
	return (nums[i]);
}

char		*ft_itoa_base(unsigned int nbr, int base)
{
	char ch;
	char *str;

	str = NULL;
	if (nbr >= (unsigned int)base)
		str = ft_itoa_base(nbr / base, base);
	ch = convert((nbr % base));
	return (ft_stradd(str, ch));
}

char		*ft_itoa_base_unsigned(size_t nbr, int base)
{
	char ch;
	char *str;

	str = NULL;
	if (nbr >= (size_t)base)
		str = ft_itoa_base_unsigned(nbr / base, base);
	ch = convert(nbr % base);
	return (ft_stradd(str, ch));
}
