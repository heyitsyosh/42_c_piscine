/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:46:27 by shutakag          #+#    #+#             */
/*   Updated: 2022/05/17 03:01:54 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*dest != '\0')
	{
		dest++;
		i++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = *src;
	dest -= i;
	return (dest);
}

char	**bsq_mem_set(t_bsq *map_info, char **av)
{
	char	**map;
	int		i;
	int		fd1;
	char	buf[BUF_SIZE];

	fd1 = open(*av, O_RDONLY);
	while (read(fd1, &buf[0], 1) == 1)
		if (buf[0] == '\n')
			break ;
	map = (char **)malloc(sizeof(char *) * (map_info->max_y + 1));
	if (map == NULL)
		map_error(map, map_info);
	i = 0;
	while (i < map_info->max_y)
	{
		map[i] = (char *)malloc(sizeof(char) * (map_info->max_x + 1));
		if (map[i] == NULL)
			map_error(map, map_info);
		read(fd1, buf, map_info->max_x + 1);
		buf[map_info->max_x] = '\0';
		ft_strcat(map[i], buf);
		i++;
	}
	close(fd1);
	return (map);
}
//map[i] not initialized (or filled) so doesn't necessarily have an '\0' needed for strcat

char	**map_init(char **map, t_bsq *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->max_y)
	{
		j = 0;
		while (j < map_info->max_x)
		{
			if (map[i][j] == map_info->empty && i * j == 0)
				map[i][j] = 1;
			else if (map[i][j] == map_info->empty)
				map[i][j] = -1;
			else if (map[i][j] == map_info->obstacle)
				map[i][j] = 0;
			else
				map_error(map, map_info);
			j++;
		}
		i++;
	}
	return (map);
}

void	create_map(char **map, t_bsq *map_info)
{
	int		i;
	int		j;

	i = 0;
	while (i < map_info->max_y)
	{
		j = 0;
		while (j < map_info->max_x)
		{
			if (map_info->y - map_info->area < i && i <= map_info->y
				&& map_info->x - map_info->area < j && j <= map_info->x)
				write(1, &map_info->full, 1);
			else if (map[i][j] == 0)
				write(1, &map_info->obstacle, 1);
			else
				write(1, &map_info->empty, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_bsq	*map_info;
	char	**map;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		map_info = set_map_info(argv + 1);
		map = bsq_mem_set(map_info, argv + 1);
		map = map_init(map, map_info);
		dynamic_programming(map, map_info);
		create_map(map, map_info);
		map_free(map, map_info);
		mapinfo_free(map_info);
		argv++;
		i++;
	}
	exit (0);
}
