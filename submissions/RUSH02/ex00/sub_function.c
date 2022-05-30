/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 22:44:13 by chtang            #+#    #+#             */
/*   Updated: 2022/02/27 09:59:45 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_space(char str)
{
	if (str == '\f' || str == '\t' || str == ' ' || \
			str == '\n' || str == '\r' || str == '\v')
		return (1);
	return (0);
}

int	is_numeric(char str)
{
	if (str > '9' || str < '0')
		return (0);
	return (1);
}

int	is_printable(char str)
{
	if (str > 126 || str < 32)
		return (0);
	return (1);
}

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(char *str)
{
	if (!str || *str == '\0')
		return (0);
	return (1 + ft_strlen(str + 1));
}
