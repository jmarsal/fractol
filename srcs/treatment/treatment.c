/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:54:07 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/25 17:02:44 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_win(t_mlx *mlx)
{
	ft_free(mlx);
	exit(0);
}

/*
** Init env, lance les calculs en fonction de la mapname et print
*/

int	start_treatment(t_fract *env, const char *mapname)
{
	int		h;
	int		w;

	h = HEIGHT_DRAW;
	w = WIDTH_DRAW;
	if (!(env = init_env(mapname)))
		return (-1);
	env->win->mlx = init_mlx();
	ft_putstr(mapname);
	mlx_hook(MLX_WIN, 17, MASK_CLOSE, close_win, &env->win->mlx);
	mlx_loop(MLX_PTR);
	return (0);
}
