/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:50:54 by zmadi             #+#    #+#             */
/*   Updated: 2019/06/14 16:10:01 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*a;
	t_list	*b;

	b = f(lst);
	a = b;
	if (lst && f)
	{
		while (lst->next != NULL)
		{
			b->next = f(lst->next);
			b = b->next;
			lst = lst->next;
		}
		return (a);
	}
	return (NULL);
}
