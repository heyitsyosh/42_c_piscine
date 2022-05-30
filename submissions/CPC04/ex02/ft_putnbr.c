/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:45:21 by myoshika          #+#    #+#             */
/*   Updated: 2022/03/04 03:21:43 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	divisor(int base, int exponent)
{
	int		x;

	x = 1;
	while (exponent > 0)
	{
		x *= base;
		exponent--;
	}
	return (x);
}

int	counter(int nb)
{
	int		counter;

	counter = 0;
	while (nb != 0)
	{
		nb /= 10;
		counter++;
	}
	return (counter);
}

void	print_num(int num)
{
	int		x;

	x = counter(num);
	while (x > 0)
	{
		ft_putchar(num / divisor(10, x - 1) % 10 + '0');
		x--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, &"-2", 2);
		print_num(147483648);
	}
	else if (nb < 0)
	{
		write(1, &"-", 1);
		print_num(-nb);
	}
	else if (nb > 0)
	{
		print_num(nb);
	}
	else if (nb == 0)
	{
		write (1, &"0", 1);
	}
}
