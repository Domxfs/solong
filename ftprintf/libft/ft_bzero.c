/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:50:45 by domy              #+#    #+#             */
/*   Updated: 2022/03/23 14:39:07 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	size_t	z;

	i = n;
	z = 0;
	if (n == 0)
	{
		return ;
	}
	else
	{
		while (i != 0)
		{
			*(char *)(s + z) = 0;
			i--;
			z++;
		}
	}
}
