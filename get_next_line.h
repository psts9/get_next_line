/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:45:00 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/14 22:07:15 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10000

typedef struct			s_filelist
{
	char				*buf;
	int					fd;
	char				*buf_pos;
	struct s_filelist	*next;
}						t_filelist;

int					get_next_line(const int fd, char **line);

#endif
