/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:05:21 by domy              #+#    #+#             */
/*   Updated: 2022/05/17 19:47:47 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lennum(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*num;

	len = ft_lennum(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_printu(unsigned int n)
{
	int		i;
	char	*res;

	i = 0;
	if (n == 0)
	{
		i += write(1, "0", 1);
	}
	else
	{
		res = ft_utoa(n);
		i = ft_putstr(res);
		free(res);
	}
	return (i);
}
