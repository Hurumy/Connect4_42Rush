/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:44:16 by taekklee          #+#    #+#             */
/*   Updated: 2023/03/14 12:35:40 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	reader_init(t_reader **preader, int fd)
{
	t_reader	*new_reader;

	*preader = NULL;
	if (BUFFER_SIZE < 1 || BUFFER_SIZE > SIZE_MAX)
		return (-1);
	new_reader = (t_reader *)malloc(1 * sizeof(t_reader));
	if (new_reader == NULL)
		return (-1);
	new_reader->fd = fd;
	if (string_init(&(new_reader->buf), BUFFER_SIZE) == -1)
	{
		free(new_reader);
		return (-1);
	}
	new_reader->buf->cap = 0;
	*preader = new_reader;
	return (0);
}

ssize_t	reader_write_buf(t_reader *reader)
{
	ssize_t	read_len;

	if (BUFFER_SIZE > INT_MAX)
		read_len = read(reader->fd, reader->buf->content, INT_MAX);
	else
		read_len = read(reader->fd, reader->buf->content, BUFFER_SIZE);
	if (read_len == -1)
		return (-1);
	reader->buf->cap = (size_t)read_len;
	reader->buf->sz = 0;
	return (read_len);
}

ssize_t	string_init(t_string **pstr, size_t size)
{
	t_string	*str;

	*pstr = NULL;
	str = (t_string *)malloc(1 * sizeof(t_string));
	if (str == NULL)
		return (-1);
	str->content = (char *)malloc(size * sizeof(char));
	if (str->content == NULL)
	{
		free(str);
		return (-1);
	}
	str->cap = size;
	str->sz = 0;
	*pstr = str;
	return (0);
}

void	*string_free(t_string **pstr)
{
	free((*pstr)->content);
	free(*pstr);
	*pstr = NULL;
	return (NULL);
}

ssize_t	string_push_back(t_string *str, char c)
{
	char	*dst;
	size_t	i;

	if (str->sz == str->cap)
	{
		if (str->cap == SIZE_MAX)
			return (-1);
		if (str->cap > SIZE_MAX / 2)
			str->cap = SIZE_MAX;
		else
			str->cap *= 2;
		dst = (char *)malloc(str->cap * sizeof(char));
		if (dst == NULL)
			return (-1);
		i = 0;
		while (i < str->sz)
		{
			dst[i] = (str->content)[i];
			++i;
		}
		free(str->content);
		str->content = dst;
	}
	(str->content)[(str->sz)++] = c;
	return (0);
}
