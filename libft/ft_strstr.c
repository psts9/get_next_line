/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:15:23 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/10 21:26:56 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int len;
	int	i;

	if (!(*needle))
		return ((char*)haystack);
	i = 0;
	len = ft_strlen(needle);
	while (haystack[i])
	{
		if (!ft_strncmp(haystack + i, needle, len))
			return ((char*)(haystack + i));
		++i;
	}
	return (NULL);
}
