/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_programming.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutakag <shunsakutakagi0618@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:01:00 by shutakag          #+#    #+#             */
/*   Updated: 2022/03/02 22:30:49 by shutakag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	map_error(char **map, t_bsq *map_info)
{
	write(2, "map error\n", 10);
	map_free(map, map_info);
	exit(1);
}

void	map_free(char **map, t_bsq *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->max_y)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	if (map != NULL)
		free(map);
}

int	bsq_min(char **map, int i, int j)
{
	if (map[i - 1][j] <= map[i][j - 1] && map[i - 1][j] <= map[i - 1][j - 1])
		return (map[i - 1][j]);
	else if (map[i][j - 1] <= map[i - 1][j - 1])
		return (map[i][j - 1]);
	else
		return (map[i - 1][j - 1]);
}

void	result_set(int y, int x, int max_area, t_bsq *map_info)
{
	map_info->y = y;
	map_info->x = x;
	map_info->area = max_area;
}

void	dynamic_programming(char **map, t_bsq *map_info)
{
	int	i;
	int	j;

	result_set(0, 0, 0, map_info);
	i = 1;
	while (i < map_info->max_y)
	{
		j = 1;
		while (j < map_info->max_x)
		{
			if (map[i][j] != 0)
			{
				map[i][j] = bsq_min(map, i, j) + 1;
				if (map[i][j] > map_info->area)
				{
					result_set(i, j, map[i][j], map_info);
				}
			}
			j++;
		}
		i++;
	}
}
