/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:02:26 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/08 23:23:33 by jmarsal          ###   ########.fr       */
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

t_data			*init_win(t_app *app)
{
	t_data	*tmp;

	tmp = NULL;
	if (app->mapname == 1 || app->mapname == 3 ||
		app->mapname == 4 || app->mapname == 5)
		tmp = init_coords_mandelbrot(app);
	else
		tmp = init_julia(app);
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
	app->menu_l = NULL;
	app->menu_b = NULL;
	app->data = NULL;
	app->fractal = NULL;
	return (app);
}

void		init_bool(t_bool *bool_button)
{
	bool_button->mandel = 0;
	bool_button->julia = 0;
	bool_button->bship = 0;
	bool_button->sword = 0;
	bool_button->chameleon = 0;
	bool_button->tricorn = 0;
	bool_button->celtic = 0;
	bool_button->my_fractal = 0;
	bool_button->exit = 0;
}

t_theme		*init_theme(void)
{
	t_theme	*theme;

	theme = ft_memalloc(sizeof(t_theme));
	theme->t1 = PINK;
	theme->t1_on = 0;
	theme->t2 = YELLOW;
	theme->t2_on = 0;
	theme->t3 = RED;
	theme->t3_on = 0;
	theme->t4 = ORANGE;
	theme->t4_on = 0;
	theme->t5 = BLUE_MENU;
	theme->t5_on = 0;
	return (theme);
}

/*
** Init app 
*/

t_app		*init_app(int map, int *h, int *w, char *mapname)
{
	t_app	*tmp;

	if (!(tmp = create_app()))
		return (NULL);
	if (map == 1)
		tmp->mapname = 1;
	else if (map == 2)
		tmp->mapname = 2;
	else if (map == 3)
		tmp->mapname = 3;
	else if (map == 4)
		tmp->mapname = 4;
	else if (map == 5)
		tmp->mapname = 5;
	else if (map == 6)
		tmp->mapname = 6;
	else if (map == 7)
		tmp->mapname = 7;
	else if (map == 8)
		tmp->mapname = 8;
	init_mlx(tmp);
	tmp->theme = init_theme();
	tmp->theme->t1_on = 1;
	tmp->background = init_img(tmp, WIDTH, HEIGHT);
	tmp->menu_l = init_left_menu(tmp, h, w);
	tmp->img = init_img(tmp, WIDTH_DRAW, HEIGHT_DRAW);
	tmp->data = init_win(tmp);
	tmp->menu_b = init_bottom_menu(tmp, h, w);
	init_bool(&tmp->bool_button);
	tmp->burger = 0;
	tmp->fractal = ft_strtoupper(mapname);
	return (tmp);
}

/*
** Free App
*/

void		app_destroy(t_app *app)
{
	ft_free(MLX_PTR);
	ft_free(app->img->img_ptr);
	ft_free(app->img->data);
	ft_free(app->img);
	ft_free(app->data);
	ft_free(app);
}
