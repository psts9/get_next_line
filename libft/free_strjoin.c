/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:35:40 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/16 18:40:32 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	free_strjoin(char **str, const char *src)
{
	char *temp;

	temp = *str;
	*str = ft_strjoin(*str, src);
	free(temp);
}
