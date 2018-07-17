/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strnjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:37:53 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/16 18:39:05 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	free_strnjoin(char **str, const char *src, size_t n)
{
	char	*temp;

	temp = *str;
	*str = ft_strnjoin(*str, src, n);
	free(temp);
}
