/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:34:29 by chtang            #+#    #+#             */
/*   Updated: 2022/02/27 22:09:08 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict{
	char	*key;
	char	*value;	
}	t_dict;

# define SUCCESS 0
# define ERROR 1
# define TRUE 1
# define FALSE 1

int		is_space(char str);
int		is_numeric(char str);
int		is_printable(char str);
int		ft_strcmp(char *str1, char *str2);
int		*ft_strdup(char *src, char **dest, int start, int end);
int		check_key(char *data, int *end);
int		check_value(char *data, int *start, int *end);
int		ft_free(void *p);
int		ft_free_2(char **p);
int		print_error(void);
int		read_file(char *file, t_dict **data, int *size);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		check_str(t_dict *dict, char *nbr);
char	*make_str(char *nbr, int start, int end);
char	*create_str(int nbr_size);
char	*create_str_10(char *nbr);
int		find_all(t_dict *dict, char *nbr, char ***outstr);

#endif
