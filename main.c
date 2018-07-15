/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:31:24 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/14 20:20:38 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

/*
** 1 line with 8 chars without Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("ret = %d\n", ret);
		if (count_lines == 0 && strcmp(line, "12345678") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 1)
		printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"12345678\" instead of \"%s\"\n", line);
	if (count_lines == 1 && errors == 0)
		printf("OK\n");
	return (0);
}
