/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 07:47:11 by chtang            #+#    #+#             */
/*   Updated: 2022/03/03 13:26:24 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	find_1(t_dict *dict, char *nbr, char ***outstr)
{
	if (!find_all(dict, nbr, outstr))
		return (SUCCESS);
	return (ERROR);
}

int	find_10(t_dict *dict, char *nbr, char ***outstr)
{
	if (!find_all(dict, nbr, outstr))
		return (SUCCESS);
	if (find_all(dict, create_str_10(nbr), outstr) == SUCCESS)
		if (find_1(dict, make_str(nbr, 1, 2), outstr) == SUCCESS)
			return (SUCCESS);
	return (ERROR);
}

int	find_100(t_dict *dict, char *nbr, char ***outstr)
{
	if (!find_all(dict, nbr, outstr))
		return (SUCCESS);
	if (find_1(dict, make_str(nbr, 0, 1), outstr) == SUCCESS)
		if (find_all(dict, create_str(3), outstr) == SUCCESS)
			if (find_10(dict, make_str(nbr, 1, 3), outstr) == SUCCESS)
				return (SUCCESS);
	return (ERROR);
}

void	start_put(t_dict *dict, int nbr_size, char *nbr, char **out_str)
{
	int	change;

	while (ft_strlen(nbr) > 0)
	{
		if (nbr_size % 3 == 0)
		{
			find_100(dict, make_str(nbr, 0, 3), &out_str);
			change = 3;
		}
		else if (nbr_size % 3 == 2)
		{
			find_10(dict, make_str(nbr, 0, 2), &out_str);
			change = 2;
		}
		else if (nbr_size % 3 == 1)
		{
			find_1(dict, make_str(nbr, 0, 1), &out_str);
			change = 1;
		}
		nbr_size = nbr_size - change + 1;
		if (nbr_size > 3)
			find_all(dict, create_str(nbr_size), &out_str);
		nbr = nbr + change;
		nbr_size = ft_strlen(nbr);
	}
	*out_str = 0;
}

//out_str
int	check_str(t_dict *dict, char *nbr)
{
	int		nbr_size;
	char	**out_str;
	int		idx;

	idx = 0;
	nbr_size = ft_strlen(nbr);
	out_str = (char **)malloc(sizeof(char *) * (nbr_size * 3 + 1));
	*out_str = 0;
	start_put(dict, nbr_size, nbr, out_str);
	while (out_str[idx])
	{
		ft_putstr(out_str[idx]);
		if (out_str[idx + 1])
			ft_putstr(" ");
		else
			ft_putstr("\n");
		idx++;
	}
	if (idx == 0 && !out_str[idx])
	{
		print_error();
		return (ERROR);
	}
	ft_free(*out_str);
	return (SUCCESS);
}
