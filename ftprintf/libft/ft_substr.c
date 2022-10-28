/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:37:53 by domy              #+#    #+#             */
/*   Updated: 2022/03/25 16:35:52 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			z;
	size_t			j;
	char			*str;

	j = 0;
	z = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (0);
	while (s[z])
	{
		if (z >= start && j < len)
		{
			str[j] = s[z];
			j++;
		}
		z++;
	}
	str[j] = 0;
	return (str);
}
