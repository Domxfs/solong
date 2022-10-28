/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:45:35 by dallocca          #+#    #+#             */
/*   Updated: 2022/10/28 19:34:48 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	check(char *name)
{
	int	fd;

	fd = open(name, O_RDWR);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_arg(int argc, t_vars *vars, char *str)
{
	if (argc != 2)
	{
		ft_printf("errore negli argomenti");
		return (0);
	}
	vars->j = 0;
	vars->passi = 0;
	if (!check(str))
	{
		ft_printf("errore nella mappa");
		return (0);
	}
	return (1);
}
