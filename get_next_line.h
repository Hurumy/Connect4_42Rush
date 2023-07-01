/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:48:42 by taekklee          #+#    #+#             */
/*   Updated: 2023/05/06 21:56:23 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define GNL_NEW_LINE (1)
# define GNL_NO_NEW_LINE (0)
# define GNL_ERROR (-1)

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_string
{
	char		*content;
	size_t		cap;
	size_t		sz;
}				t_string;

typedef struct s_reader
{
	int			fd;
	t_string	*buf;
}				t_reader;

char		*get_next_line(int fd, int *newline);
ssize_t		reader_init(t_reader **preader, int fd);
ssize_t		reader_write_buf(t_reader *reader);
void		reader_free(t_reader **preader);
ssize_t		string_init(t_string **pstr, size_t size);
void		*string_free(t_string **pstr);
ssize_t		string_push_back(t_string *str, char c);
char		*string_to_cstring(t_string **pstr, int *newline);

#endif
