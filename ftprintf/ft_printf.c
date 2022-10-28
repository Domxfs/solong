/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:36:55 by dallocca          #+#    #+#             */
/*   Updated: 2022/05/19 17:40:07 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags(va_list lista, const char band)
{
	int	y;

	y = 0;
	if (band == 'c')
		y += ft_putchar(va_arg(lista, int));
	if (band == 's')
		y += ft_putstr(va_arg(lista, char *));
	if (band == 'd')
		y += ft_putnbr(va_arg(lista, int));
	if (band == '%')
		y += ft_perc();
	if (band == 'i')
		y += ft_putnbr(va_arg(lista, int));
	if (band == 'u')
		y += ft_printu(va_arg(lista, unsigned int));
	if (band == 'p')
		y += ft_xp(va_arg(lista, uintptr_t), band);
	if (band == 'X' || band == 'x')
		y += ft_xp(va_arg(lista, unsigned int), band);
	return (y);
}

int	ft_printf(const char *str, ...)
{
	int		z;
	int		x;
	va_list	diff;

	x = 0;
	z = 0;
	va_start(diff, str);
	while (str[x])
	{
		if (str[x] == '%')
		{
			z += flags(diff, str[x + 1]);
			x++;
		}
		else
		{
			z += ft_putchar(str[x]);
		}
		x++;
	}
	va_end(diff);
	return (z);
}
