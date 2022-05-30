/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tosave.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:30:45 by shutakag          #+#    #+#             */
/*   Updated: 2022/03/03 06:41:45 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	mapinfo_free(t_bsq *map_info)
{
	if (map_info != NULL)
		free(map_info);
}

void	mapinfo_error(t_bsq *map_info)
{
	write(2, "map error\n", 10);
	mapinfo_free(map_info);
	exit(1);
}

void	make_symbols(char *first_line, int first_line_len, t_bsq *map_info)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (i < first_line_len - 3)
	{
		if (32 > first_line[i] || first_line[i] > 126)
			mapinfo_error(map_info);
		nbr = nbr * 10 + (first_line[i] - '0');
		i++;
	}
	map_info->max_y = nbr;
	map_info->empty = first_line[i];
	map_info->obstacle = first_line[i + 1];
	map_info->full = first_line[i + 2];
	if (map_info->empty == map_info->obstacle
		|| map_info->obstacle == map_info->full
		|| map_info->full == map_info->empty)
		mapinfo_error(map_info);
}

void	get_second_line(char **av, t_bsq *map_info)
{
	int		fd1;
	char	c;
	int		second_line_len;
	int		i;

	fd1 = open(*av, O_RDONLY);
	while (read(fd1, &c, 1) == 1)
		if (c == '\n')
			break ;
	read(fd1, &c, 1);
	map_info->max_x = 0;
	i = -1;
	while (++i < map_info->max_y)
	{
		second_line_len = 1;
		while (read(fd1, &c, 1) == 1 && c != '\n')
			second_line_len++;
		if (map_info->max_x == 0)
			map_info->max_x = second_line_len;
		else if (map_info->max_x != second_line_len)
			mapinfo_error(map_info);
		read(fd1, &c, 1);
	}
	close(fd1);
}

struct s_bsq	*set_map_info(char **av)
{
	t_bsq	*map_info;
	int		fd1;
	char	*first_line;
	char	c;
	int		first_line_len;

	map_info = malloc(sizeof(t_bsq));
	fd1 = open(*av, O_RDONLY);
	if (fd1 == -1 || map_info == NULL)
		mapinfo_error(map_info);
	first_line_len = 0;
	while (read(fd1, &c, 1) == 1 && c != '\n')
		first_line_len++;
	if (first_line_len < 4)
		mapinfo_error(map_info);
	first_line = malloc(sizeof(char) * (first_line_len + 1));
	close(fd1);
	fd1 = open(*av, O_RDONLY);
	read(fd1, first_line, first_line_len + 1);
	make_symbols(first_line, first_line_len, map_info);
	close(fd1);
	get_second_line(av, map_info);
	return (map_info);
}
