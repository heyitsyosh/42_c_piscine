/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owner <owner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 03:31:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/02/27 18:33:45 by owner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *src, int i)
{
	while (src[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dst_len;
	unsigned int	src_len;

	i = 0;
	src_len = ft_strlen(src, 0);
	dst_len = ft_strlen(dest, 0);
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && dst_len + i < size - 1)
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	dest[dst_len + i] = '\0';
	return (dst_len + src_len);
}
