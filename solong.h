/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dallocca <dallocca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:50:45 by dallocca          #+#    #+#             */
/*   Updated: 2022/10/28 20:27:55 by dallocca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include	<mlx.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<math.h>
# include	<fcntl.h>
# include	"ftprintf/ft_printf.h"
# include	"get_next_line/get_next_line.h"

typedef struct s_data {
	void		*muro;
	void		*sfondo;
	void		*player;
	void		*coin;
	void		*exit;
	char		**mat;
	int			size[2];

}	t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*window;
	t_data		data;
	int			x;
	int			y;
	int			j;
	int			i;
	int			passi;
	t_data		img;
}	t_vars;

int		check(char *name);
int		check_arg(int argc, t_vars *vars, char *str);
int		check_exit(t_vars *vars);
int		check_coin(t_vars *vars);
int		check_wall(t_vars *vars);
int		check_player(t_vars *vars);
int		check_size(t_vars *vars);
int		final_checker(t_vars *vars);
int		ft_input(int key, void *param);
void	personal_mlx(t_vars *vars, void *img, int x, int y);
void	generation(t_vars *vars);
void	ft_image(t_vars *vars, int x, int y);
void	calc_mappa(char *name, t_vars *vars);
int		mapread(char *name, t_vars *vars);
int		check_char(char *str, t_vars *vars);
int		ber_check(char *c, char *s);
void	startimage(t_vars *vars);
int		event(int keycode, t_vars *vars);
int		controllo_coll(t_vars *vars);
void	ft_passi(t_vars *vars);
void	refresh(int j, int i, t_vars *vars);
int		ft_close(void);

#endif
