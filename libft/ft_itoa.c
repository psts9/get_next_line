/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:50:58 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/12 00:28:00 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int rslt;

	rslt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		++rslt;
	while (n != 0)
	{
		n /= 10;
		++rslt;
	}
	return (rslt);
}

static void	nlz(char **result, int *n)
{
	(*result)[0] = '-';
	(*n) *= -1;
}

static char	*set_to_intmin(void)
{
	char *p;

	p = ft_strnew(11);
	p = ft_strcpy(p, "-2147483648");
	return (p);
}

char		*ft_itoa(int n)
{
	int		i;
	int		i_size;
	char	*result;

	if (n == -2147483648)
	{
		result = set_to_intmin();
		return (result);
	}
	i_size = numlen(n);
	result = ft_strnew(i_size);
	if (!result)
		return (NULL);
	if (n < 0)
		nlz(&result, &n);
	i = 1;
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[i_size - i++] = ((n % 10) + '0');
		n /= 10;
	}
	result[i_size] = '\0';
	return (result);
}
