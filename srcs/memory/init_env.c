/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:02:26 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/25 16:58:48 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = NULL;
	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx_ptr = mlx_init()))
	{
		ft_free(mlx);
		return (NULL);
	}
	if (!(mlx->mlx_win =
		mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, TITLE)))
	{
		ft_free(mlx->mlx_ptr);
		ft_free(mlx);
		return (NULL);
	}
	return (mlx);
}

static void	init_win(t_print **win)
{
	t_print	*tmp;

	tmp = *win;
	tmp->mlx = NULL;
	tmp->img = NULL;
}

/*
** Init env 
*/

t_fract		*init_env(const char *mapname)
{
	t_fract	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_fract))))
		return (NULL);
	tmp->map_name = (char*)mapname;
	if (!(tmp->win = ft_memalloc(sizeof(t_print))))
		return (NULL);
	init_win(&tmp->win);
	(void)mapname;
	return (tmp);
}

