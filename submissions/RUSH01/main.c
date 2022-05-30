/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misato <misato>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:01:06 by misato            #+#    #+#             */
/*   Updated: 2022/02/20 20:25:22 by misato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char arr[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};

	int y;
	int	i;
	int str[16];

	y = 0;
	i = 0;
	error (argv);
	
	arr = case(argv);
	y = solve(arr, str, 0);

	if (y == 1)
		display_grid(arr);
	else
		write(2, &"Error", 6);
	return (0);
}