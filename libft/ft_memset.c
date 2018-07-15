/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:40:32 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/11 15:45:44 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t len)
{
	size_t			i;
	unsigned char	u_char;
	char			*temp;

	i = 0;
	u_char = (unsigned char)c;
	temp = p;
	while (i < len)
	{
		*temp = u_char;
		++temp;
		++i;
	}
	return (p);
}
