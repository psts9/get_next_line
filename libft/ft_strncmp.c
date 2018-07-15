/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:47:50 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/10 21:12:46 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		rslt;

	i = 0;
	while ((s1[i] && s2[i]) && (i < n))
	{
		rslt = ((unsigned char)s1[i]) - ((unsigned char)s2[i]);
		if (rslt != 0)
			return (rslt);
		++i;
	}
	if (i != n)
		return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
	else
		return (0);
}
