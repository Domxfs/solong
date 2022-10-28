/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:15:25 by domy              #+#    #+#             */
/*   Updated: 2022/03/23 14:47:34 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	z;

	z = 0;
	if (!s)
		return (NULL);
	while (z < n)
	{
		if (*(unsigned char *)(s + z) == (unsigned char)c)
			return ((void *)(z + s));
		z++;
	}
	return (NULL);
}
