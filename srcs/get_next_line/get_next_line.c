/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:03:24 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/13 11:46:26 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*substr(char *str, int start, int end)
{
	char	*ret;
	int		idx;

	if (start >= end)
		return (0);
	idx = 0;
	ret = ft_calloc(sizeof(char), (end - start + 2));
	while (start < end)
		ret[idx++] = str[start++];
	ret[idx] = 0;
	return (ret);
}

int	find(char *str, int start, int end, char target)
{
	while (start < end && str[start])
	{
		if (str[start++] == target)
			return (start - 1);
	}
	return (-1);
}

static int	read_to_buf(int fd, char *buf, int *idx, int *end)
{
	int	ret;
	int	temp;

	if (BUFFER_SIZE < 0)
		return (-1);
	*end = *idx;
	temp = find(buf, 0, *end, '\n');
	ret = BUFFER_SIZE;
	while (temp == -1 && ret == BUFFER_SIZE)
	{
		ret = read(fd, buf + *end, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		temp = find(buf, *end, *end + ret, '\n');
		*end += ret;
	}
	if (temp == -1)
		*idx = *end - 1;
	else
		*idx = temp;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffers[4096][BUFFER_SIZE];
	int			idx;
	int			end;
	char		*txt;

	if (fd < 0 || fd > 4096)
		return (0);
	idx = ft_strlen(buffers[fd]);
	if (read_to_buf(fd, buffers[fd], &idx, &end) == -1 || idx == -1)
		return (0);
	end = end - idx - 1;
	txt = substr(buffers[fd], 0, idx + 1);
	ft_memcpy(buffers[fd], buffers[fd] + idx + 1, end);
	buffers[fd][end] = 0;
	return (txt);
}
