/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:38:39 by domy              #+#    #+#             */
/*   Updated: 2022/05/19 15:54:59 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		z++;
	}
	return (z);
}

int	ft_putnbr(int c)
{
	int	i;

	i = 0;
	if (c == -2147483648)
	{
		i += ft_putnbr(c / 10);
		i += write (1, "8", 1);
	}
	else if (c < 0)
	{
		i += write (1, "-", 1);
		i += ft_putnbr(-c);
	}
	else
	{
		if (c > 9)
		{
			i += ft_putnbr(c / 10);
		}
		i += ft_putchar(48 + c % 10);
	}
	return (i);
}

int	ft_perc(void)
{
	write(1, "%", 1);
	return (1);
}
