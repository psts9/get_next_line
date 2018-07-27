/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:50:06 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/26 18:04:10 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "get_next_line.h"

#define FL_BUFS (filelist->buf_pos_start)
#define FL_BUFE (filelist->buf_pos_end)

static t_filelist	*new_filelist(const int fd)
{
	t_filelist	*list;

	list = malloc(sizeof(t_filelist));
	if (!list)
		return (NULL);
	if (fd < 0)
	{
		free(list);
		return (NULL);
	}
	list->buf = (char*)malloc(BUFF_SIZE + 1);
	if (!(list->buf))
	{
		free(list);
		return (NULL);
	}
	list->fd = fd;
	list->buf_pos_start = list->buf;
	list->buf_pos_end = NULL;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

static int			read_from_file(const int fd, t_filelist **list)
{
	int rd;

	rd = read(fd, (*list)->buf, BUFF_SIZE);
	if (rd <= 0)
	{
		if (rd < 0)
			return (-1);
		else
			return (0);
	}
	(*list)->buf[rd] = '\0';
	(*list)->buf_pos_start = (*list)->buf;
	(*list)->buf_pos_end = (*list)->buf;
	return (1);
}

static int			search_filelist(t_filelist **list, t_filelist **tmp, int f)
{
	*tmp = NULL;
	while (*list)
	{
		*tmp = *list;
		*list = (*list)->prev;
	}
	*list = *tmp;
	while (*list)
	{
		if ((*list)->fd == f)
			return (1);
		*tmp = *list;
		*list = (*list)->next;
	}
	return (0);
}

static int			open_fd(const int fd, t_filelist **list)
{
	int			rd;
	t_filelist	*temp;
	t_filelist	*add;

	if (search_filelist(list, &temp, fd))
		return (1);
	if (!temp)
	{
		if (!(*list = new_filelist(fd)))
			return (-1);
	}
	else
	{
		*list = temp;
		if (!(add = new_filelist(fd)))
			return (-1);
		(*list)->next = add;
		*list = (*list)->next;
		(*list)->prev = temp;
	}
	rd = read_from_file(fd, list);
	return (rd);
}

int					get_next_line(const int fd, char **line)
{
	static t_filelist	*filelist;
	int					rd;

	if (!line)
		return (-1);
	if ((rd = open_fd(fd, &filelist)) <= 0)
		return (rd);
	*line = ft_strnew(0);
	while ((*(filelist->buf_pos_end) != '\n') && rd != 0)
	{
		((*(filelist->buf_pos_end)) ? ++(filelist->buf_pos_end) : 0);
		if (!(*(filelist->buf_pos_end)))
		{
			free_strjoin(line, filelist->buf_pos_start);
			rd = read_from_file(fd, &filelist);
			if (rd < 0)
				return (-1);
			else if (rd == 0 && FL_BUFS == FL_BUFE)
				return (0);
		}
	}
	if (filelist->buf_pos_end[0] == '\n')
		free_strnjoin(line, FL_BUFS, FL_BUFE - FL_BUFS);
	filelist->buf_pos_start = ++(filelist->buf_pos_end);
	return (1);
}
