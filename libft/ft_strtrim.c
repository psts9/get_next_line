/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:53:47 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/12 00:31:10 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		beg;
	int		end;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	if (!s[i])
		return (ft_memalloc(1));
	beg = i;
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
		--i;
	end = i;
	p = ft_strnew(end - beg + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (beg <= end)
		p[i++] = s[beg++];
	return (p);
}
