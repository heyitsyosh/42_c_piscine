/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:23:01 by myoshika          #+#    #+#             */
/*   Updated: 2022/02/22 00:58:03 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = size - 1;
	while (i < (size / 2))
	{
		k = tab[i];
		tab[i] = tab[j];
		tab[j] = k;
		i++;
		j--;
	}
}
