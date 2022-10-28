/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:37:31 by domy              #+#    #+#             */
/*   Updated: 2022/03/25 16:11:44 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str2;
	int		l;
	int		source;
	int		dest;

	source = 0;
	dest = 0;
	l = ft_strlen(s1);
	str2 = malloc((l + 1) * sizeof(char));
	while (s1[source])
	{
		str2[dest] = s1[source];
		source++;
		dest++;
	}
	str2[dest] = '\0';
	return (str2);
}
