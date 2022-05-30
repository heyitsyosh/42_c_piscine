/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:13:44 by myoshika          #+#    #+#             */
/*   Updated: 2022/02/19 16:22:55 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char status)
{
	write(1, &status, 1);
}

void	ft_is_negative(int num)
{
	if (num < 0)
	{
		ft_putchar('N');
	}
	else
	{
		ft_putchar('P');
	}
}
