/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:50:06 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/14 19:08:23 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "get_next_line.h"

static t_filelist	*new_filelist(const int fd)
{
	t_filelist	*list;

	list = malloc(sizeof(t_filelist));
	if (!list)
		return (NULL);
	if (fd < 0)
		return (NULL);
	list->buf = (char*)malloc(BUFF_SIZE + 1);
	if (!(list->buf))
		return (NULL);
	list->fd = fd;
	list->buf_pos = list->buf;
	list->next = NULL;
	return (list);
}

static int			read_from_file(const int fd, t_filelist **list)
{
	int rd;

	if (!(*list))
		*list = new_filelist(fd);
	rd = read(fd, (*list)->buf, BUFF_SIZE);
	if (rd <= 0)
	{
		(*list) = NULL;
		if (rd < 0)
			return (-1);
		else
			return (0);
	}
	(*list)->buf[rd] = '\0';
	(*list)->buf_pos = (*list)->buf;
	return (1);
}

char				*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = ft_strnew(ft_strlen(s1) + n);
	if (!result)
		return (NULL);
	result = ft_strcpy(result, s1);
	result = ft_strncat(result, s2, n);
	return (result);
}

int					is_unique_fd(const int fd, t_filelist *list)
{
	while (list)
	{
		if (list->fd == fd)
			return (0);
		list = list->next;
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_filelist	*filelist;
	int					rd;

	if (!filelist || is_unique_fd(fd, filelist))
	{
		filelist = new_filelist(fd);
		rd = read_from_file(fd, &filelist);
		if (rd <= 0)
			return (rd);
	}
	// read only when at end of buffer!!
	*line = ft_strnew(0); // most likely don't change
	while (*(filelist->buf_pos) != '\n')
	{
		if (*(filelist->buf_pos))
			++(filelist->buf_pos);
		if (!(*(filelist->buf_pos))) // if we reached the end of the buffer
		{
			*line = ft_strjoin(*line, filelist->buf);
			rd = read_from_file(fd, &filelist);
			if (rd <= 0)
				return (rd);
		}
	}
	if (*(filelist->buf_pos) == '\n')
	{
		*line = ft_strnjoin(*line, filelist->buf, filelist->buf_pos - filelist->buf);
		++(filelist->buf_pos);
	}
	filelist->buf = filelist->buf_pos;
	return (1);
}
