/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:21:47 by dallocca          #+#    #+#             */
/*   Updated: 2022/10/28 19:39:56 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	check_exit(t_vars *vars)
{
	int	x;
	int	y;
	int	index;

	x = 0;
	y = 0;
	index = 0;
	while (y < vars->data.size[0])
	{
		x = 0;
		while (x < vars->data.size[1])
		{
			if (vars->data.mat[y][x] == 'E')
				index++;
			x++;
		}
		y++;
	}
	return (index);
}

int	check_coin(t_vars *vars)
{
	int	x;
	int	y;
	int	index;

	x = 0;
	y = 0;
	index = 0;
	while (y < vars->data.size[0])
	{
		x = 0;
		while (x < vars->data.size[1])
		{
			if (vars->data.mat[y][x] == 'C')
				index++;
			x++;
		}
		y++;
	}
	return (index);
}

int	check_wall(t_vars *vars)
{
	int	y;
	int	x;

	y = -1;
	while (++y < vars->data.size[0])
	{
		x = -1;
		while (++x < vars->data.size[1])
		{
			if (vars->data.mat[0][x] != '1' || \
				vars->data.mat[vars->data.size[0] - 1][y] != '1' || \
				vars->data.mat[y][0] != '1' || \
				vars->data.mat[y][vars->data.size[1] - 1] != '1' || \
				vars->data.size[1] != ft_strlen(vars->data.mat[y]))
			{
				return (0);
			}
		}
	}
	return (1);
}

int	check_player(t_vars *vars)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	x = 0;
	y = 0;
	while (y < vars->data.size[0])
	{
		x = 0;
		while (x < vars->data.size[1])
		{
			if (vars->data.mat[y][x] == 'P')
				index++;
			x++;
		}
		y++;
	}
	return (index);
}

int	check_size(t_vars *vars)
{
	int	x;
	int	size;

	x = 0;
	size = ft_strlen(vars->data.mat[0]);
	while (x < vars->data.size[0])
	{
		if (size != (int)ft_strlen(vars->data.mat[x]))
		{
			ft_printf("Erorre nella forma della mappa");
			return (0);
		}
		x++;
	}
	return (1);
}
