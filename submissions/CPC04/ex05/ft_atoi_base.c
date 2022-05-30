/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:45:28 by myoshika          #+#    #+#             */
/*   Updated: 2022/03/01 17:16:29 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_base(char *base)
{
	int	base_len;
	int	i;

	base_len = 0;
	while (base[base_len])
	{
		if (base[base_len] == '+' || base[base_len] == '-'
			|| base[base_len] == ' ')
			return (0);
		if (base[base_len] == 32
			|| (base[base_len] <= 13 && base[base_len] >= 9))
			return (0);
		i = base_len + 1;
		while (base[i])
		{
			if (base[base_len] == base[i])
				return (0);
			i++;
		}
		base_len++;
	}
	if (base_len < 2)
		return (0);
	return (base_len);
}

int	get_int(char c, char *base, int i)
{
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	base_len;
	int	res_int;
	int	sign;

	i = 0;
	res_int = 0;
	sign = 1;
	base_len = check_base(base);
	if (!check_base(base))
		return (0);
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == ' ')
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ((str[i] >= '0') && (str[i] <= '9')))
	{
		res_int = (res_int * base_len) + (get_int(str[i], base, 0));
		i++;
	}
	return (sign * res_int);
}
