/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:00:12 by domy              #+#    #+#             */
/*   Updated: 2022/05/19 17:51:36 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_putchar(int c);
int		flags(va_list lista, const char band);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int c);
int		ft_lennum(unsigned int n);
int		ft_chlen(uintptr_t i);
int		ft_putstr(char *str);
int		ft_xp(uintptr_t n, char i);
int		ft_perc(void);
char	*ft_utoa(unsigned int n);
int		ft_printu(unsigned int n);

#endif
