/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:02:26 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/02 17:04:11 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img		*init_img(t_app *app, int width, int height)
{
	t_img	*img;

	img = NULL;
	if (!(img = ft_memalloc(sizeof(t_img))))
		return (NULL);
	img->img_ptr = mlx_new_image(app->mlx, width, height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	return (img);
}

void		init_mlx(t_app *app)
{
	if (!(app->mlx->mlx_ptr = mlx_init()))
	{
		ft_free(app->mlx);
		exit (-1);
	}
	if (!(app->mlx->mlx_win =
		mlx_new_window(app->mlx->mlx_ptr, WIDTH, HEIGHT, TITLE)))
	{
		ft_free(app->mlx->mlx_ptr);
		ft_free(app->mlx);
		exit (-1);
	}
}

static t_data	*init_win(t_app *app)
{
	t_data	*tmp;

	tmp = NULL;
	init_img(app, WIDTH_DRAW, HEIGHT_DRAW);
	if (app->map_name == 1)
		tmp = init_coords_mandelbrot();
	return (tmp);
}

static t_app	*create_app(void)
{
	t_app	*app;

	if (!(app = ft_memalloc(sizeof(t_app))))
		return (NULL);
	app->mapname = NULL;
	app->mlx = NULL;
	app->win = NULL;
	app->img = NULL;
	app->data = NULL;
	return (app);
}

/*
** Init app 
*/

t_app		*init_app(const char *mapname)
{
	t_app	*tmp;

	if (!(tmp = create_app()))
		return (NULL);
	if (!ft_strcmp(mapname, "mandelbrot"))
		tmp->map_name = 1;
	if (!(tmp->win = ft_memalloc(sizeof(t_print))))
		return (NULL);
	init_mlx(app);
	tmp->img = init_img(app, WIDTH_DRAW, HEIGHT_DRAW);
	tmp->data = init_win(app);
	return (tmp);
}

/*
** Free App
*/

void		env_destroy(t_app *app)
{
	ft_free(app->mlx->mlx_ptr);
	ft_free(app->mlx->mlx_win);
	ft_free(app->mlx);
	ft_free(app->win->img->img_ptr);
	ft_free(app->win->img->data);
	ft_free(app->win->img);
	ft_free(app->win);
	ft_free(app->img->img_ptr);
	ft_free(app->img->data);
	ft_free(app->img);
	ft_free(app->data);
	ft_free(app);
}
