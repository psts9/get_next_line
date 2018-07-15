/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:08:28 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/10 19:33:27 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	while (i < n)
	{
		result = ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i];
		if (result != 0)
			return (result);
		++i;
	}
	return (0);
}
