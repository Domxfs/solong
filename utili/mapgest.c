/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:02:42 by dallocca          #+#    #+#             */
/*   Updated: 2022/10/28 20:19:46 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	calc_mappa(char *name, t_vars *vars)
{
	int		fd;
	char	*string;

	fd = open(name, O_RDWR);
	vars->data.size[0] = 0;
	string = get_next_line(fd);
	if (!string)
	{
		ft_printf("mappa invalida 1");
		exit(0);
	}
	vars->data.size[1] = ft_strlen(string);
	while (string)
	{
		free(string);
		vars->data.size[0]++;
		string = get_next_line(fd);
	}
	close (fd);
}

int	mapread(char *name, t_vars *vars)
{
	char	*string;
	int		i;
	int		fd;

	i = 0;
	fd = open(name, O_RDWR);
	vars->data.mat = (char **)ft_calloc((vars->data.size[0] + 1),
			sizeof(char *));
	string = get_next_line(fd);
	while (i < vars->data.size[0])
	{
		if (!string)
			return (0);
		vars->data.mat[i] = string;
		i++;
		string = get_next_line(fd);
	}
	return (1);
}

int	check_char(char *str, t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < vars->data.size[0])
	{
		x = 0;
		while (x < vars->data.size[1])
		{
			if (!ft_strchr(str, vars->data.mat[y][x]))
			{
				ft_printf("errore nella mappa (caratteri)");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ber_check(char *c, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	i = i - 3;
	while (j++ < 4)
	{
		if (c[j] != s[i])
		{
			ft_printf("Errore nel .ber");
			return (0);
		}
		i++;
	}
	return (1);
}
