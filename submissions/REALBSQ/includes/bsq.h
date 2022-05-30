/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutakag <shunsakutakagi0618@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:22:45 by shutakag          #+#    #+#             */
/*   Updated: 2022/03/02 22:49:05 by shutakag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF_SIZE 512

typedef struct s_bsq
{
	int		max_x;
	int		max_y;
	char	empty;
	char	obstacle;
	char	full;
	int		x;
	int		y;
	int		area;
}	t_bsq;

void			make_symbols(char *f_l, int f_l_len, t_bsq *map_info);
void			get_second_line(char **av, t_bsq *map_info);
struct s_bsq	*set_map_info(char **av);
void			map_error(char **map, t_bsq *map_info);
void			mapinfo_error(t_bsq *map_info);
char			**bsq_mem_set(t_bsq *map_info, char **av);
char			**map_init(char **map, t_bsq *map_info);
void			create_map(char **map, t_bsq *map_info);
void			map_free(char **map, t_bsq *map_info);
void			mapinfo_free(t_bsq *map_info);
int				bsq_min(char **map, int i, int j);
void			result_set(int y, int x, int max_area, t_bsq *map_info);
void			dynamic_programming(char **map, t_bsq *map_info);

#endif //BSQ_H