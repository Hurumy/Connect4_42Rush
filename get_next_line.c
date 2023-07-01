/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:52:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/04/26 14:20:56 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*get_next_line_from(t_reader **preader, int *newline);
static ssize_t	add_one_char(t_string *str, t_reader *reader);

char	*get_next_line(int fd, int *newline)
{
	static t_reader	*reader;

	*newline = GNL_ERROR;
	if (reader != NULL && reader->fd != fd)
		reader_free(&reader);
	if (reader == NULL && reader_init(&reader, fd) == -1)
		return (NULL);
	return (get_next_line_from(&reader, newline));
}

static char	*get_next_line_from(t_reader **preader, int *newline)
{
	ssize_t		res;
	t_string	*line;

	if (string_init(&line, 1) == -1)
		return (NULL);
	res = 1;
	while (res == 1)
		res = add_one_char(line, *preader);
	if (res == -1 || (res == 0 && line->sz == 0))
	{
		if (res == 0 && line->sz == 0)
		{
			reader_free(preader);
			*newline = GNL_NO_NEW_LINE;
		}
		return (string_free(&line));
	}
	return (string_to_cstring(&line, newline));
}

static ssize_t	add_one_char(t_string *str, t_reader *reader)
{
	ssize_t	res;
	char	c;

	if (reader->buf->sz == reader->buf->cap)
	{
		res = reader_write_buf(reader);
		if (res == -1 || res == 0)
			return (res);
	}
	c = (reader->buf->content)[(reader->buf->sz)++];
	if (string_push_back(str, c) == -1)
		return (-1);
	if (c == '\n')
		return (0);
	return (1);
}

char	*string_to_cstring(t_string **pstr, int *newline)
{
	char	*content;
	size_t	i;

	content = (char *)malloc(((*pstr)->sz + 1) * sizeof(char));
	if (content == NULL)
		return (string_free(pstr));
	i = 0;
	while (i < (*pstr)->sz)
	{
		content[i] = ((*pstr)->content)[i];
		++i;
	}
	content[(*pstr)->sz] = '\0';
	if ((*pstr)->sz > 0 && content[(*pstr)->sz - 1] == '\n')
	{
		content[(*pstr)->sz - 1] = '\0';
		*newline = GNL_NEW_LINE;
	}
	else
		*newline = GNL_NO_NEW_LINE;
	string_free(pstr);
	return (content);
}

void	reader_free(t_reader **preader)
{
	string_free(&((*preader)->buf));
	free(*preader);
	*preader = NULL;
}
