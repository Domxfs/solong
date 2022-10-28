/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:44:32 by dallocca          #+#    #+#             */
/*   Updated: 2022/10/28 20:24:02 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (check_arg(argc, &vars, argv[1]) == 0)
		return (0);
	calc_mappa(argv[1], &vars);
	if (!mapread(argv[1], &vars) || !check_char("PEC01", &vars) || \
			!final_checker(&vars) || !ber_check(".ber", argv[1]))
	{
		free(&vars);
		return (0);
	}
	startimage(&vars);
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, vars.data.size[1] * 80,
			vars.data.size[0] * 80, "molto lungo!");
	generation(&vars);
	mlx_key_hook(vars.window, event, &vars);
	mlx_hook(vars.window, 17, (1L << 5), ft_close, NULL);
	mlx_loop(vars.mlx);
}
