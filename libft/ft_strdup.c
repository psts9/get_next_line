/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:18:40 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/11 19:11:45 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;

	len = ft_strlen(s1);
	p = ft_strnew(len);
	if (p)
	{
		ft_memcpy(p, s1, len);
		return (p);
	}
	else
		return (NULL);
}
