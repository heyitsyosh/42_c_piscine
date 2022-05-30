/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case1:4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misato <misato>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:49:08 by misato            #+#    #+#             */
/*   Updated: 2022/02/20 20:21:15 by misato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	case(int str, int arr)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 1)
		{
			put_arr_1(i);
			i++;
		}
		else if (str[i] == 4)
		{
			put_arr_4(i);
			i++;
		}
		else
		i++;
	}
}

int	put_arr_4(i)
{
	int arr[4][4];
	
	if (i < 4)
	{//x = tate    y = yoko
		arr[i + 1][i + 1] = 1;
		arr[i + 1][i + 2] = 2;
		arr[i + 1][i + 3] = 3;
		arr[i + 1][i + 4] = 4;
	}
	else if (i < 8)
	{
		arr[i - 4][i - 4] = 4;
		arr[i - 4][i - 3] = 3; 
		arr[i - 4][i - 2] = 2;
		arr[i - 4][i - 1] = 1;
	}
	else if (i < 12)
	{
		arr[i - 7][i - 7] = 1;
		arr[i - 7][i - 6] = 2;
		arr[i - 7][i - 5] = 3;
		arr[i - 7][i - 4] = 4;
	}
	else if (i < 16)
	{
		arr[i - 8][i - 8] = 1;
		arr[i - 8][i - 9] = 2;
		arr[i - 8][i - 10] = 3;
		arr[i - 8][i - 11] = 4;
	}
	return(0);
}

int	put_arr_1 (i)
{
	int arr[4][4];
	
	if(i < 4)
	{
		arr[1][i + 1] = 4;
	}
	else if (i < 8)
	{
		arr[4][i - 1] = 4;
	}
	else if (i < 12)
	{
		arr[i - 7][1] = 4;
	}
	else if (i < 16)
	{
		arr[i - 11][4] = 4;
	}
	return (0);
}

int	main(void)
{
	int x; //tate
	int y; //yoko

	x = 4;
	y = 4;

	int arr[x][y];
	// = {
	// 	{0, 0, 0, 0},
	// 	{0, 0, 0, 0},
	// 	{0, 0, 0, 0},
	// 	{0, 0, 0, 0},
	// };

	int str [16] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";

case(str, arr);

printf("%d", arr[x][y]);
}

