/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:57:59 by domy              #+#    #+#             */
/*   Updated: 2022/03/25 16:12:05 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	size_t	l1;
	size_t	l2;
	int		z;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	z = 0;
	str = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	while (s1[i])
	{
		str[z++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[z++] = s2[i];
		i++;
	}
	str[z] = 0;
	return (str);
}
