/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:31:24 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/15 22:27:12 by pthorell         ###   ########.fr       */
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
	int			fd1, fd2, fd3;
	int			ret;
	int			count_lines;
	int			errors;

	count_lines = 0;
	errors = 0;
	line = NULL;
	fd1 = open("test_file", O_RDONLY);
	int i = 0;
	while ((ret = get_next_line(fd1, &line)) > 0)
	{
		printf("fd = %d, string = %s\n", fd1, line);
		sleep(10);
	}
	/*
	while (i++ < 2)
	{
		get_next_line(fd1, &line);
		printf("fd = %d, string = %s\n", fd1, line);
		//printf("ret = %d\n", ret);
	}
	fd2 = open("test_file_3", O_RDONLY);
	while (i++ < 5)
	{
		get_next_line(fd2, &line);
		printf("fd = %d, string = %s\n", fd2, line);
	}
	fd3 = open("afile", O_RDONLY);
	while ((ret = get_next_line(fd3, &line)) > 0)
	{
		printf("fd = %d, string = %s\n", fd3, line);
	}
	while (i++ < 10)
	{
		get_next_line(fd2, &line);
		printf("fd = %d, string = %s\n", fd2, line);
	}
	while ((ret = get_next_line(fd1, &line)) > 0)
	{
		printf("fd = %d, string = %s\n", fd1, line);
	}
	while ((ret = get_next_line(fd3, &line)) > 0)
		printf("fd = %d, string = %s\n", fd3, line);
	sleep(1000);
	*/
	return (0);
}
