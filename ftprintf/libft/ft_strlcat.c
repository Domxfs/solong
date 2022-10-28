/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:43:00 by domy              #+#    #+#             */
/*   Updated: 2022/03/23 15:03:11 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	m;
	size_t	i;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	m = 0;
	i = d;
	if (dstsize <= 0)
		return (s);
	if (dstsize <= d)
		return (s + dstsize);
	else
	{
		while (src[m] != '\0' && d + m < dstsize)
			dst[i++] = src[m++];
		if ((d + m) == dstsize && d < dstsize)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (s + d);
	}
}
