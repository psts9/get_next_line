/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:57:05 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/10 23:33:36 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*p;

	i = 0;
	p = malloc(size);
	if (p)
	{
		while (i < size)
		{
			((char*)p)[i] = 0;
			++i;
		}
	}
	else
		return (NULL);
	return (p);
}
