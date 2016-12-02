/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:02:26 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/02 09:34:10 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img		*init_img(t_app *app, int width, int height)
{
	t_img	*img;

	img = NULL;
	if (!(img = ft_memalloc(sizeof(t_img))))
	{
		// print_error(app->err, 3);
		return (NULL);
	}
	img->img_ptr = mlx_new_image(app->win->mlx, width, height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	(void)app;
		(void)width;
			(void)height;
	return (img);
}

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
	tmp->mlx = init_mlx();
}

/*
** Init app 
*/

t_app		*init_env(const char *mapname)
{
	t_app	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_app))))
		return (NULL);
	tmp->map_name = (char*)mapname;
	if (!(tmp->win = ft_memalloc(sizeof(t_print))))
		return (NULL);
	// if (!(tmp->win->coords = ft_memalloc(sizeof(t_coords *))))
	// 	return (NULL);
	init_win(&tmp->win);
	init_img(tmp, WIDTH_DRAW, HEIGHT_DRAW);
	(void)mapname;
	return (tmp);
}

void		env_destroy(t_app *app)
{
	ft_free(app->win->mlx->mlx_ptr);
	ft_free(app->win->mlx->mlx_win);
	ft_free(app->win->mlx);
	ft_free(app->win->img->img_ptr);
	ft_free(app->win->img->data);
	ft_free(app->win->img);
	ft_free(app->win);
	ft_free(app);
}
