/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:45:17 by bmarlin           #+#    #+#             */
/*   Updated: 2020/02/23 14:45:17 by bmarlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;

	if (lst && f)
	{
		new_list = (*f)(lst);
		if (lst->next && new_list)
			new_list->next = ft_lstmap(lst->next, f);
		return (new_list);
	}
	return (NULL);
}
