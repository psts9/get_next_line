/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 23:16:13 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/11 16:01:59 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	p = ft_strnew(len);
	if (!p || !s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[start + i];
		++i;
	}
	p[i] = '\0';
	return (p);
}
