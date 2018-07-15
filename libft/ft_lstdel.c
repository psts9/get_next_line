/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:14:03 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/12 00:01:25 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *curr;
	t_list *next;

	curr = *alst;
	while (curr)
	{
		next = curr->next;
		ft_lstdelone(&curr, del);
		curr = next;
	}
	*alst = NULL;
}
