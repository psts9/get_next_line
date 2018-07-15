/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:43:53 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/10 14:29:09 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while ((i < len) && (src[i]))
	{
		if (src[i])
			dst[i] = src[i];
		++i;
	}
	while (i < len)
	{
		dst[i] = '\0';
		++i;
	}
	return (dst);
}
