/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:43:50 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/12 19:42:52 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p;
	size_t	i;

	p = dst;
	i = 0;
	while (i < n)
	{
		p[i] = ((char*)src)[i];
		++i;
	}
	return (dst);
}
