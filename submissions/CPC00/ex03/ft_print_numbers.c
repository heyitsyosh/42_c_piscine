/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:13:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/02/19 16:22:10 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int num)
{
	write(1, &num, 1);
}

void	ft_print_numbers(void)
{
	char	num;

	num = 48;
	while (num < 58)
	{
		ft_putchar(num);
		num++;
	}
}
