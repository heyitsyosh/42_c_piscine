/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:40:27 by myoshika          #+#    #+#             */
/*   Updated: 2022/03/04 14:53:33 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*mem;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	mem = malloc(sizeof(int) * (max - min));
	if (mem == NULL)
		return (NULL);
	while (min + i < max)
	{
		mem[i] = min + i;
		i++;
	}
	return (mem);
}
