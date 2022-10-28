/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   immagine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:24:05 by dallocca          #+#    #+#             */
/*   Updated: 2022/10/28 19:42:30 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	personal_mlx(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->window, img, x, y);
}

void	generation(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->data.size[0])
	{
		x = 0;
		while (x < vars->data.size[1])
		{
			ft_image(vars, x, y);
			x++;
		}
		y++;
	}
}

void	ft_image(t_vars *vars, int x, int y)
{
	if (vars->data.mat[y][x] == '1')
		personal_mlx(vars, vars->img.muro, x * 80, y * 80);
	else if (vars->data.mat[y][x] == '0')
		personal_mlx(vars, vars->img.sfondo, x * 80, y * 80);
	else if (vars->data.mat[y][x] == 'C')
	{
		personal_mlx(vars, vars->img.sfondo, x * 80, y * 80);
		personal_mlx(vars, vars->img.coin, x * 80, y * 80);
	}
	else if (vars->data.mat[y][x] == 'P')
	{
		vars->x = y;
		vars->y = x;
		personal_mlx(vars, vars->img.sfondo, x * 80, y * 80);
		personal_mlx(vars, vars->img.player, x * 80, y * 80);
	}
	else if (vars->data.mat[y][x] == 'E')
	{
		personal_mlx(vars, vars->img.sfondo, x * 80, y * 80);
		personal_mlx(vars, vars->img.exit, x * 80, y * 80);
	}
}

int	ft_close(void)
{
	exit (0);
	return (0);
}

int	final_checker(t_vars *vars)
{
	if (!check_size(vars))
		return (0);
	if (!check_wall(vars))
	{
		ft_printf("errore nei muri\n");
		return (0);
	}
	if (!check_coin(vars))
	{
		ft_printf("errore nelle monete\n");
		return (0);
	}
	if (check_player(vars) != 1)
	{
		ft_printf("errore nei player\n");
		return (0);
	}
	if (!check_exit(vars))
	{
		ft_printf("errore nelle uscite\n");
		return (0);
	}
	return (1);
}
