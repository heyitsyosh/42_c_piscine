/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:16:08 by myoshika          #+#    #+#             */
/*   Updated: 2022/02/26 00:42:10 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char chr)
{
	char			*hex;
	unsigned char	arr[2];

	hex = "0123456789abcdef";
	arr[0] = hex[chr / 16];
	arr[1] = hex[chr % 16];
	write(1, arr, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ft_putchar('\\');
			print_hex(((unsigned char)str[i]));
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
