/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:45:25 by myoshika          #+#    #+#             */
/*   Updated: 2022/03/01 16:52:55 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	valid_base(char *base, int x, int check_dbl)
{
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[x])
	{
		check_dbl = x + 1;
		if (base[x] < 32 || base[x] > 126)
			return (0);
		else if (base[x] == '+' || base[x] == '-')
			return (0);
		while (base[check_dbl])
		{
			if (base[x] == base[check_dbl])
				return (0);
			check_dbl++;
		}
		x++;
	}
	return (1);
}

long long	if_negative(long long lnbr)
{
	if (lnbr < 0)
	{
		write(1, &"-", 1);
		lnbr *= -1;
	}
	return (lnbr);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = size - 1;
	while (i < (size / 2))
	{
		k = tab[i];
		tab[i] = tab[j];
		tab[j] = k;
		i++;
		j--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	i;
	int			digit;
	long long	lnbr;

	i = 1;
	lnbr = (long long)nbr;
	digit = ft_len(base);
	if (!(digit) || !(valid_base(base, 0, 0)))
		return ;
	lnbr = if_negative(lnbr);
	while (lnbr / digit >= i)
		i *= digit;
	while (i > 0)
	{
		write(1, &base[lnbr / i], 1);
		lnbr %= i;
		i /= digit;
	}
	return ;
}
