/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:26:41 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/11 22:55:37 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		if (content)
		{
			list->content = (void*)malloc(content_size);
			if (list->content)
				ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
		else
		{
			list->content = NULL;
			list->content_size = 0;
		}
		list->next = NULL;
	}
	else
		return (NULL);
	return (list);
}
