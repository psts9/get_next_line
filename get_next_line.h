/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:45:00 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/15 22:24:19 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2

typedef struct			s_filelist
{
	char				*buf;
	int					fd;
	char				*buf_pos_end;
	char				*buf_pos_start;
	struct s_filelist	*next;
	struct s_filelist	*prev;
}						t_filelist;

int					get_next_line(const int fd, char **line);

#endif
