/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:02:26 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/04 00:50:57 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img		*init_img(t_app *app, int width, int height)
{
	t_img	*img;

	img = NULL;
	if (!(img = ft_memalloc(sizeof(t_img))))
		return (NULL);
	img->img_ptr = mlx_new_image(MLX_PTR, width, height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	return (img);
}

void		init_mlx(t_app *app)
{
	if (!(MLX_PTR = mlx_init()))
		exit (-1);
	if (!(MLX_WIN =
		mlx_new_window(MLX_PTR, WIDTH, HEIGHT, TITLE)))
	{
		ft_free(MLX_PTR);
		exit (-1);
	}
}

static t_data	*init_win(t_app *app)
{
	t_data	*tmp;

	tmp = NULL;
	// app->img = init_img(app, WIDTH_DRAW, HEIGHT_DRAW);
	if (app->mapname == 1)
		tmp = init_coords_mandelbrot();
	return (tmp);
}

static t_app	*create_app(void)
{
	t_app	*app;

	if (!(app = ft_memalloc(sizeof(t_app))))
		return (NULL);
	app->mapname = 0;
	MLX_PTR = NULL;
	MLX_WIN = NULL;
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
		tmp->mapname = 1;
	init_mlx(tmp);
	tmp->background = init_img(tmp, WIDTH, HEIGHT);
	tmp->img_ico = init_img(tmp, 64, 64);
	tmp->bordure_left = init_img(tmp, WIDTH, HEIGHT);
	tmp->bordure_right = init_img(tmp, WIDTH, HEIGHT);
	tmp->bordure_top = init_img(tmp, WIDTH, HEIGHT);
	tmp->bordure_bottom = init_img(tmp, WIDTH, HEIGHT);
	tmp->one = init_img(tmp, 32, 32);
	tmp->img = init_img(tmp, WIDTH_DRAW, HEIGHT_DRAW);
	tmp->data = init_win(tmp);
	return (tmp);
}

/*
** Free App
*/

void		env_destroy(t_app *app)
{
	ft_free(MLX_PTR);
	ft_free(MLX_WIN);
	ft_free(app->img->img_ptr);
	ft_free(app->img->data);
	ft_free(app->img);
	ft_free(app->data);
	ft_free(app);
}
