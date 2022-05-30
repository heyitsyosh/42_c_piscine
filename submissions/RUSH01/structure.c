/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misato <misato>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:33:01 by misato            #+#    #+#             */
/*   Updated: 2022/02/20 20:33:54 by misato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdlib.h> 


int check_double(int arr[4][4], int pos, int size) 
/*checking for duplicates in column and rows. / and % by four because of grid size
num is the size of the skyscraper being checked btw.
*/
{
	int i;

	i = 0;
	while (i != 4) //check rows or vertically
	{
		if (arr[i][pos % 4] != 0)
			return (1);
		else
			i++;
	}
	while (i != 4)
	{
		if (arr[pos / 4][i] != 0) //check columns or horizontally
			return (1);
		else
			i++;
	}
	return (0);
}

int check_col_up(int arr[4][4], int pos, int entry[16])
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (arr[i][pos % 4] > max)
			{
				max = arr[i][pos % 4];
				count++;
			}
			i--;
		}
		if (entry[pos % 4] != count)
			return (1);
	}
	return (0);
}

int check_col_down(int arr[4][4], int pos, int entry[16])
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (arr[pos % 4][i] > max)
			{
				max = [pos % 4][i];
				count++;
			}
			i++;
		}
		if (entry[pos % 4] != count)
			return (1);
	}
	return (0);
}

int check_row_right(int arr[4][4], int pos, int entry[16])
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (arr[i][pos / 4] > max)
			{
				max = arr[i][pos / 4];
				count++;
			}
			i--;
		}
		if (entry[pos / 4] != count)
			return (1);
	}
	return (0);
}

int check_row_left(int arr[4][4], int pos, int entry[16])
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if ([pos / 4][i] > max)
			{
				max = arr[pos / 4][i];
				count++;
			}
			i++;
		}
		if (entry[pos / 4] != count)
			return (1);
	}
	return (0);
}

int check_case(int arr[4][4], int pos, int entry[16])
{
	if (check_row_left(arr, pos, entry) == 1)
		return (1);
	if (check_row_right(arr, pos, entry) == 1)
		return (1);
	if (check_col_down(arr, pos, entry) == 1)
		return (1);
	if (check_col_up(arr, pos, entry) == 1)
		return (1);
	return (0);
}

int solve(int arr[4][4], int entry[16], int pos)
{
	int	size;

	if (pos == 16)
		return(1);

	size = 1; //size of skyscraper to place
	while (size <= 4)
	{
		if (check_double(arr, pos, size) == 0)
			arr[pos / 4][pos % 4] = size;
		else 
		size++;
		
		if (check_case(arr, pos, entry) == 0)
		{
					if (solve(arr, entry, pos + 1) == 1) //check for next possibility
					return (1);
				}
				else
					arr[pos / 4][pos % 4] = 0;
			}
		size++;
	}
	write(2, &"Error", 6);
	return (0); //no solutions
}

