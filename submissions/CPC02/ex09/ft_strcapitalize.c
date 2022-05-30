/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:16:03 by myoshika          #+#    #+#             */
/*   Updated: 2022/02/24 22:29:39 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (new_word == 1 && str[i] >= '0' && str[i] <= '9')
			new_word = 0;
		else if (new_word == 1 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			new_word = 0;
		}
		else if (new_word == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		else if (new_word == 1 && str[i] >= 'A' && str[i] <= 'Z')
			new_word = 0;
		else if (!(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z')
			&& !(str[i] >= '0' && str[i] <= '9'))
			new_word = 1;
		i++;
	}
	return (str);
}
