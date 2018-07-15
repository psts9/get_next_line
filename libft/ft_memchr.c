/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:44:32 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/10 19:31:42 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	u_char;
	size_t			i;

	i = 0;
	u_char = (unsigned char)c;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == u_char)
			return (&((unsigned char*)s)[i]);
		++i;
	}
	return (NULL);
}
