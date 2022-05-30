/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:44:13 by chtang            #+#    #+#             */
/*   Updated: 2022/02/27 07:45:42 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	trim_back(char *data, int idx)
{
	while (is_space(data[idx]))
		idx--;
	idx++;
	return (idx);
}

int	check_key(char *data, int *end)
{
	int	idx;
	int	is_end;

	idx = 0;
	is_end = 0;
	while (data[idx] && is_numeric(data[idx]) && data[idx] != ':')
		idx++;
	while (is_space(data[idx]) || data[idx] == ':')
	{
		if (is_end == 0)
		{
			is_end = 1;
			*end = idx;
		}
		if (data[idx] == ':')
			return (SUCCESS);
		idx++;
	}
	return (ERROR);
}

int	check_value(char *data, int *start, int *end)
{
	int	idx;
	int	is_start;

	idx = 0;
	is_start = 0;
	while (data[idx] && data[idx] != ':')
		idx++;
	idx++;
	while (is_space(data[idx]))
		idx++;
	while (is_printable(data[idx]) || data[idx] == '\0')
	{
		if (is_start == 0)
		{
			is_start = 1;
			*start = idx;
		}
		if (data[idx] == '\0')
		{
			*end = trim_back(data, idx - 1);
			return (SUCCESS);
		}
		idx++;
	}
	return (ERROR);
}
