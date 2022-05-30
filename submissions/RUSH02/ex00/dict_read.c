/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 01:41:52 by chtang            #+#    #+#             */
/*   Updated: 2022/02/28 23:48:59 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	get_buf_size(int fd, int *size, char ***tmp, char **buf)
{
	int		buf_size;
	char	c;

	buf_size = 1;
	*size = 1;
	while (read(fd, &c, 1))
	{
		buf_size++;
		if (c == '\n')
			(*size)++;
	}
	*buf = (char *) malloc (sizeof(char) * (buf_size + 1));
	if (!(*buf))
		return (0);
	*tmp = (char **) malloc (sizeof(char *) * buf_size * 2);
	if (!(*tmp))
		return (0);
	return (buf_size);
}

int	save_tmp(char *buf, char ***tmp, int *size)
{
	int	idx;
	int	start;
	int	end;

	idx = 0;
	start = 0;
	end = 0;
	if (*size == 1)
		return (ERROR);
	while (buf[end])
	{
		if (buf[end] == '\n')
		{
			ft_strdup(buf, &((*tmp)[idx]), start, end);
			idx++;
			start = end + 1;
		}
		end++;
	}
	(*tmp)[idx] = 0;
	return (SUCCESS);
}

int	save_data(char **tmp, t_dict **data, int *size)
{
	int	start;
	int	end;
	int	idx;

	idx = 0;
	*data = (t_dict *) malloc (sizeof(t_dict) * *size);
	if (!*data)
		return (ERROR);
	while (tmp[idx])
	{
		if (check_key(tmp[idx], &end))
			return (ERROR);
		ft_strdup(tmp[idx], &((*data)[idx].key), 0, end);
		if (check_value(tmp[idx], &start, &end))
			return (ERROR);
		ft_strdup(tmp[idx], &((*data)[idx].value), start, end);
		idx++;
	}
	(*data)[idx].key = 0;
	(*data)[idx].value = 0;
	return (SUCCESS);
}

//tmp, buf created
int	read_file(char *file, t_dict **data, int *size)
{
	int		fd;
	int		buf_size;
	char	*buf;
	char	**tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	buf_size = get_buf_size(fd, size, &tmp, &buf);
	if (buf_size == 0 || close(fd) == -1)
		return (ERROR + ft_free(tmp) + ft_free(buf));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ERROR + ft_free(tmp) + ft_free(buf));
	read(fd, buf, buf_size - 1);
	
	if (save_tmp(buf, &tmp, size) || save_data(tmp, data, size))
		return (ERROR);
	if (close(fd) == -1)
		return (ERROR + ft_free(tmp) + ft_free(buf));
	return (SUCCESS + ft_free(tmp) + ft_free(buf));
}
