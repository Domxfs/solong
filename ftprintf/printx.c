/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:21:44 by dallocca          #+#    #+#             */
/*   Updated: 2022/05/19 17:52:03 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_basech(uintptr_t c, char *i)
{
	if (c < 0)
	{
		ft_putchar('-');
		ft_basech(-c, i);
	}
	if (c >= 16)
	{
		ft_basech(c / 16, i);
		ft_putchar(i[c % 16]);
	}
	else if (c >= 0)
	{
		ft_putchar(i[c % 16]);
	}
}

int	ft_chlen(uintptr_t i)
{
	int	p;

	p = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 16;
		p++;
	}
	return (p);
}

int	ft_xp(uintptr_t n, char i)
{
	int		c;
	char	*str;

	c = ft_chlen(n);
	if (i == 'p')
	{
		write(1, "0x", 2);
		c += 2;
		str = "0123456789abcdef";
		ft_basech(n, str);
	}
	else if (i == 'X')
	{
		str = "0123456789ABCDEF";
		ft_basech(n, str);
	}
	else
	{
		str = "0123456789abcdef";
		ft_basech(n, str);
	}
	return (c);
}
