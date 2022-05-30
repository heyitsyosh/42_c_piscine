/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 07:04:01 by myoshika          #+#    #+#             */
/*   Updated: 2022/03/01 17:47:59 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
	write(1, &"\n", 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = argc;
	while (--i > 0)
		ft_putstr(argv[i]);
	return (0);
}
