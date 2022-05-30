/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:13:53 by myoshika          #+#    #+#             */
/*   Updated: 2022/02/19 17:22:50 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_combn(int num, char arr[])
{
	int		b;
	char	max_dig;

	max_dig = '0' + (10 - num);
	b = 0;
	while (b < num)
	{
		ft_putchar(arr[b]);
		b++;
	}
	if (arr[0] != max_dig)
	{
		write(1, ", ", 2);
	}
}

void	rec(int a, int index, char arr[], int num)
{
	if (a < num)
	{
		while (index < 10)
		{
			arr[a] = '0' + index;
			rec(a + 1, index + 1, arr, num);
			index++;
		}
	}
	else
		print_combn(num, arr);
}

void	ft_print_combn(int n)
{
	char		arr[9];

	if (n > 10 || n < 0)
		return ;
	rec(0, 0, arr, n);
}
