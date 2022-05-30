/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:02:57 by cheyang           #+#    #+#             */
/*   Updated: 2022/03/03 18:39:44 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_input_2(char **argv)
{
	int	idx;

	idx = 0;
	while (argv[1][idx])
	{
		if (argv[1][idx] > '9' || argv[1][idx] < '0')
		{
			write(1, "Error\n", 6);
			return (ERROR);
		}
		idx++;
	}
	return (0);
}

int	check_input_3(char **argv)
{
	int	idx;

	idx = 0;
	while (argv[1][idx])
	{
		if (!is_numeric(argv[1][idx]))
		{
			write(1, "Error\n", 6);
			return (ERROR);
		}
		idx++;
	}
	idx = 0;
	while (argv[2][idx])
	{
		if (is_printable(argv[2][idx]))
		{
			print_error();
			return (ERROR);
		}
		idx++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_dict	*data;
	int		size;

	if (argc == 2)
	{
		if (check_input_2(argv) == ERROR)
			return (0);
		if (read_file("numbers.dict", &data, &size) == ERROR)
			return (0);
		check_str(data, argv[1]);
		return (0 + ft_free(data));
	}
	if (argc == 3)
	{
		if (check_input_3(argv) == ERROR)
			return (0);
		if (read_file(argv[2], &data, &size) == ERROR)
			return (0);
		check_str(data, argv[2]);
		return (0 + ft_free(data));
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
