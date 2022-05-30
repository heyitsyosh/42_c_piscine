/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:16:11 by myoshika          #+#    #+#             */
/*   Updated: 2022/02/25 19:25:11 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_front(int j, unsigned char *p)
{
	long		div;
	int			i;
	long		tmp;
	intptr_t	print;

	i = 0;
	div = 1;
	print = (intptr_t)(p + j);
	while (i < 15)
	{
		div *= 16;
		i++;
	}
	while (div > 0)
	{
		if (print / div < 10)
			tmp = (print / div) + '0';
		else
			tmp = (print / div) - 10 + 'a';
		ft_putchar(tmp);
		print %= div;
		div /= 16;
	}
	write(1, &": ", 2);
}

void	print_hex(int i, unsigned int size, unsigned char *p)
{
	char			*hex;
	unsigned int	j;

	j = 0;
	hex = "0123456789abcdef";
	while (j < 16 && i + j < size)
	{
		ft_putchar((char)hex[(*(p + i + j) / 16) % 16]);
		ft_putchar((char)hex[*(p + i + j) % 16]);
		if ((j % 2) == 1)
			write(1, &" ", 1);
		j++;
	}
	while (j < 16)
	{
		write(1, &"  ", 2);
		if ((j % 2) == 1)
			write(1, &" ", 1);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;
	unsigned char	*p;

	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_print_front(i, p);
		print_hex(i, size, p);
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (*(p + i + j) >= 32 && *(p + i + j) <= 126)
				ft_putchar((char)*(p + i + j));
			else
				write(1, &".", 1);
			j++;
		}
		write(1, &"\n", 1);
		i += 16;
	}
	return (addr);
}
