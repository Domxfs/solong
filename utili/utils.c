/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:52:25 by dallocca          #+#    #+#             */
/*   Updated: 2022/10/28 19:53:13 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	startimage(t_vars *vars)
{
	int	x;
	int	y;

	vars->img.sfondo = mlx_xpm_file_to_image(vars->mlx,
			"sprites/sfondo.xpm", &x, &y);
	vars->img.muro = mlx_xpm_file_to_image(vars->mlx,
			"sprites/wall.xpm", &x, &y);
	vars->img.coin = mlx_xpm_file_to_image(vars->mlx,
			"sprites/coin.xpm", &x, &y);
	vars->img.exit = mlx_xpm_file_to_image(vars->mlx,
			"sprites/exit.xpm", &x, &y);
	vars->img.player = mlx_xpm_file_to_image(vars->mlx,
			"sprites/player.xpm", &x, &y);
}

int	event(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->window);
	if (keycode == 53)
		exit (0);
	else if (keycode == 2)
		refresh (1, 0, vars);
	else if (keycode == 1)
		refresh (0, 1, vars);
	else if (keycode == 0)
		refresh (-1, 0, vars);
	else if (keycode == 13)
		refresh (0, -1, vars);
	generation (vars);
	return (0);
}

int	controllo_coll(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->data.size[0])
	{
		x = 0;
		while (x < vars->data.size[1])
		{
			if (vars->data.mat[y][x] == 'C')
			{
				write(1, "prima colleziona tutte le monete\n", 30);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_passi(t_vars *vars)
{
	vars->passi++;
	ft_printf("numero di passi : %i\n", vars->passi);
}

void	refresh(int j, int i, t_vars *vars)
{
	if (vars->data.mat[vars-> x + i][vars->y + j] == '0')
	{
		vars->data.mat[vars->x][vars->y] = '0';
		vars->data.mat[vars->x + i][vars->y + j] = 'P';
		ft_passi(vars);
	}
	if (vars->data.mat[vars-> x + i][vars->y + j] == 'C')
	{
		vars->data.mat[vars->x][vars->y] = '0';
		vars->data.mat[vars->x + i][vars->y + j] = 'P';
		ft_passi(vars);
	}
	if (vars->data.mat[vars-> x + i][vars->y + j] == 'E')
	{
		if (controllo_coll(vars))
		{
			ft_passi(vars);
			exit(0);
		}
	}
}
