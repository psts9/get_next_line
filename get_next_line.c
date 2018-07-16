/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:50:06 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/15 22:27:01 by pthorell         ###   ########.fr       */
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

	list = malloc(sizeof(t_filelist)); // malloc not cleared
	if (!list)
		return (NULL);
	if (fd < 0)
	{
		free(list);
		return (NULL);
	}
	list->buf = (char*)malloc(BUFF_SIZE + 1); // malloc not cleared
	if (!(list->buf))
	{
		free(list);
		return (NULL);
	}
	list->fd = fd;
	list->buf_pos_start = list->buf;
	list->buf_pos_end = list->buf;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

static int			read_from_file(const int fd, t_filelist **list)
{
	int rd;

	(*list)->buf = (char*)malloc(BUFF_SIZE + 1);
//	sleep(10);
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

char				*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = ft_strnew(ft_strlen(s1) + n); // malloc not cleared
	if (!result)
		return (NULL);
	result = ft_strcpy(result, s1);
	result = ft_strncat(result, s2, n);
	return (result);
}

int			open_fd(const int fd, t_filelist **list)
{
	int			rd;
	t_filelist	*temp;
	t_filelist	*add;

	temp = NULL;
	while (*list)
	{
		temp = *list;
		*list = (*list)->prev;
	}
	*list = temp;
	while (*list)
	{
		if ((*list)->fd == fd)
			return (1);
		temp = *list;
		*list = (*list)->next;
	}
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

void				del_filelist(t_filelist **list)
{
	t_filelist *prev;
	t_filelist *next;

	prev = (*list)->prev;
	next = (*list)->next;
	if ((*list)->buf)
	{
		free((*list)->buf);
		(*list)->buf = NULL;
	}
	free(*list);
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
}

int					get_next_line(const int fd, char **line)
{
	static t_filelist	*filelist;
	char				*temp;
	int					rd;

	if (fd < 0)
		return (-1);
	if ((rd = open_fd(fd, &filelist)) <= 0)
		return (rd);
//	sleep(10);
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
//	*line = ft_strnew(0);
//	sleep(10);
	while (*(filelist->buf_pos_end) != '\n')
	{
		if (*(filelist->buf_pos_end))
			++(filelist->buf_pos_end);
		else
		{
			temp = ft_strnew(ft_strlen(*line));
			temp = ft_strcpy(temp, *line);
			*line = ft_strjoin(temp, filelist->buf_pos_start);
			free(temp);
			rd = read_from_file(fd, &filelist);
			if (rd < 0)
				return (-1);
			else if (rd == 0 && filelist->buf_pos_start == filelist->buf_pos_end)
			{
				//printf("fd = %d\n", filelist->fd);
				return (0);
			}
			else if (rd == 0)
				break ;
		}
	}
//	sleep(10);
	if (filelist->buf_pos_end[0] == '\n')
	{
		temp = ft_strnew(ft_strlen(*line));
		temp = ft_strcpy(temp, *line);
		*line = ft_strnjoin(temp, filelist->buf_pos_start, filelist->buf_pos_end - filelist->buf_pos_start);
		free(temp);
	}
	++(filelist->buf_pos_end);
	filelist->buf_pos_start = filelist->buf_pos_end;
//	sleep(10);
	return (1);
}
