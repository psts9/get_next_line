/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:30:08 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/11 16:04:06 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		s_len;
	size_t	i;

	if (len == 0)
		return (NULL);
	if (!(*needle))
		return ((char*)haystack);
	i = 0;
	s_len = ft_strlen(needle);
	while (haystack[i] && (int)i <= ((int)len - s_len))
	{
		if (!ft_strncmp(haystack + i, needle, s_len))
			return ((char*)(haystack + i));
		++i;
	}
	return (NULL);
}
