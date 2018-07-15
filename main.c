/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:54:09 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/14 18:48:55 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"

void	open_and_read(char *file)
{
	int fd;
	char *next_line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		puts("thats bad");
	else
	{
		int i = 0;
		while (get_next_line(42, &next_line) > 0)
		{
			puts(next_line);
			sleep(1);
		}
	}
}

int	main(void)
{
	puts("test 1:");
	sleep(1);
	open_and_read("test_file");
	sleep(1);
	puts("test 2:");
	sleep(1);
	open_and_read("test_file_2");
	sleep(1);
	puts("test 3:");
	sleep(1);
	open_and_read("test_file_3");
	
	return (0);
}
