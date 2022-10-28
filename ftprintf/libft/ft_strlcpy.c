/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:14:55 by domy              #+#    #+#             */
/*   Updated: 2022/03/23 15:04:46 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	m;
	size_t	i;
	size_t	z;

	i = 0;
	m = 0;
	z = 0;
	while (src[i] != '\0')
	{
		m++;
		i++;
	}
	if (!dstsize)
	{
		return (m);
	}
	while (src[z] && z < dstsize - 1)
	{
		dst[z] = src[z];
		z++;
	}
	dst[z] = '\0';
	return (m);
}
