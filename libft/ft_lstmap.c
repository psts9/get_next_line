/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:42:50 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/11 20:16:04 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	node_count(t_list *lst)
{
	int result;

	result = 0;
	while (lst)
	{
		lst = lst->next;
		++result;
	}
	return (result);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *result;

	if (!lst)
		return (NULL);
	result = malloc(sizeof(t_list) * node_count(lst));
	if (!result)
		return (NULL);
	result = f(lst);
	head = result;
	lst = lst->next;
	while (lst)
	{
		result->next = f(lst);
		result = result->next;
		lst = lst->next;
	}
	return (head);
}
