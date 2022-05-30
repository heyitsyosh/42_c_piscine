/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:13:49 by myoshika          #+#    #+#             */
/*   Updated: 2022/02/19 17:21:11 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnum(int num)
{
	char	first;
	char	second;
	int		tempfirst;
	int		tempsecond;

	if (num < 10)
	{
		first = '0';
		second = '0' + num;
		write(1, &first, 1);
		write(1, &second, 1);
	}
	else
	{
		tempfirst = num / 10;
		tempsecond = num % 10;
		first = '0' + tempfirst;
		second = '0' + tempsecond;
		write(1, &first, 1);
		write(1, &second, 1);
	}
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			putnum(a);
			write(1, &" ", 1);
			putnum(b);
			if (a == 98 && b == 99)
				return ;
			else
				write(1, &", ", 2);
			b++;
		}
		a++;
	}
}
