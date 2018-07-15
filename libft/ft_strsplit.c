/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:31:17 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/11 16:19:35 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strtil(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		++i;
	return (i);
}

static int	ft_strnumsplit(char const *s, char c)
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		if (!s[i])
			return (result);
		else if (s[i] != c)
			++result;
		while (s[i] && s[i] != c)
			++i;
	}
	return (result);
}

static void	set_to_zero(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

static void	skip_to_valid(char const *s, char c, int *i)
{
	while (s[*i] == c && s[*i])
		++(*i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		istrlen;
	int		i;
	int		x;

	if (!s)
		return (NULL);
	result = (char**)malloc(sizeof(char*) * (ft_strnumsplit(s, c) + 1));
	if (!result)
		return (NULL);
	set_to_zero(&i, &x);
	while (s[i])
	{
		skip_to_valid(s, c, &i);
		if (!s[i])
			break ;
		istrlen = ft_strtil(s + i, c);
		result[x] = ft_strnew(istrlen);
		if (!result[x])
			return (NULL);
		ft_strncpy(result[x++], s + i, istrlen);
		i += ft_strtil(s + i, c);
	}
	result[x] = NULL;
	return (result);
}
