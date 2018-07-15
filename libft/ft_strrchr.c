/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:56:36 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/11 15:46:52 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	u_char;
	int				i;

	u_char = (unsigned int)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == u_char)
			return ((char*)&s[i]);
		--i;
	}
	return (NULL);
}
