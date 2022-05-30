/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_function_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:44:13 by chtang            #+#    #+#             */
/*   Updated: 2022/02/27 20:57:58 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	*ft_strdup(char *src, char **dest, int start, int end)
{
	int		idx;

	idx = 0;
	if (src == 0)
		return (0);
	*dest = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (dest == 0)
		return (NULL);
	while (src[idx + start] && (idx + start) < end)
	{
		(*dest)[idx] = src[idx + start];
		idx++;
	}
	(*dest)[idx] = '\0';
	return (SUCCESS);
}

int	ft_free(void *p)
{
	if (p != 0)
		free(p);
	return (0);
}

int	print_error(void)
{
	write(1, "Dict Error\n", 11);
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}
