/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:18:11 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/10 18:55:14 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	u_char;
	unsigned char	*p;

	i = 0;
	u_char = (unsigned char)c;
	p = dst;
	while (i < n)
	{
		*p = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == u_char)
			return (++p);
		++p;
		++i;
	}
	return (NULL);
}
