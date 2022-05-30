/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 07:03:57 by myoshika          #+#    #+#             */
/*   Updated: 2022/03/01 17:53:34 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*arr;
	int		i;

	i = 0 + argc - argc;
	arr = argv[0];
	while (arr[i])
	{
		write(1, &arr[i], 1);
		i++;
	}
	write(1, &"\n", 1);
	return (0);
}
