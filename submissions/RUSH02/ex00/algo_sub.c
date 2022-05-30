/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:55:42 by chtang            #+#    #+#             */
/*   Updated: 2022/03/01 00:10:35 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*make_str(char *nbr, int start, int end)
{
	char	*str;
	int		idx;

	idx = 0;
	str = (char *) malloc (sizeof(char) * 4);
	while (idx < 4)
	{
		str[idx] = '\0';
		idx++;
	}
	idx = 0;
	while (idx < (end - start))
	{
		str[idx] = nbr[start + idx];
		idx++;
	}
	return (str);
}

//create 1 * 10^ (nbr_size - 1)
char	*create_str(int nbr_size)
{
	char	*temp_nbr;
	int		idx;

	idx = 1;
	temp_nbr = (char *) malloc (sizeof(char) * (nbr_size + 1));
	temp_nbr[0] = '1';
	while (idx < nbr_size)
	{
		temp_nbr[idx] = '0';
		idx++;
	}
	temp_nbr[idx] = '\0';
	return (temp_nbr);
}

char	*create_str_10(char *nbr)
{
	char	*temp_nbr;
	int		idx;

	idx = 1;
	temp_nbr = (char *) malloc (sizeof(char) * (3));
	temp_nbr[0] = nbr[0];
	while (idx < 2)
	{
		temp_nbr[idx] = '0';
		idx++;
	}
	temp_nbr[idx] = '\0';
	return (temp_nbr);
}

int	find_all(t_dict *dict, char *nbr, char ***outstr)
{
	int	idx;

	idx = 0;
	while (dict[idx].key)
	{
		if (ft_strcmp(nbr, dict[idx].key) == 0)
		{
			ft_strdup(dict[idx].value, *outstr, 0, ft_strlen(dict[idx].value));
			(*outstr)++;
			return (SUCCESS);
		}
		idx++;
	}
	return (ERROR);
}
