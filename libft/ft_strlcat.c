/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:12:59 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/11 15:50:09 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		max;
	size_t	i;
	int		j;
	size_t	len;
	int		c;

	len = ft_strlen(dst);
	max = dstsize - len - 1;
	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		++i;
	c = i;
	while (i < dstsize && src[j] && j < max)
	{
		dst[i] = src[j];
		++i;
		++j;
	}
	if (dstsize != 0 && len <= dstsize)
		dst[i] = '\0';
	return (c + ft_strlen(src));
}
