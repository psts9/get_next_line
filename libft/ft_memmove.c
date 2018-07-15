/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 14:17:37 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/11 15:53:51 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (dst <= src)
	{
		while (i < (int)len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			++i;
		}
	}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			((char*)dst)[i] = ((char*)src)[i];
			--i;
		}
	}
	return (dst);
}
