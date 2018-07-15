/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:36:25 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/10 22:00:05 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int rslt;

	i = 0;
	while (s1[i] && s2[i])
	{
		rslt = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (rslt != 0)
			return (rslt);
		++i;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
