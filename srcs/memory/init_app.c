/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:02:26 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 11:51:47 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static void		get_mapname(int map, t_app *app)
{
	if (map == 1)
		app->mapname = 1;
	else if (map == 2)
		app->mapname = 2;
	else if (map == 3)
		app->mapname = 3;
	else if (map == 4)
		app->mapname = 4;
	else if (map == 5)
		app->mapname = 5;
	else if (map == 6)
		app->mapname = 6;
	else if (map == 7)
		app->mapname = 7;
	else if (map == 8)
		app->mapname = 8;
}

/*
** Init app
*/

t_app			*init_app(int map, int *h, int *w, char *mapname)
{
	t_app	*tmp;

	if (!(tmp = create_app()))
		return (NULL);
	get_mapname(map, tmp);
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

void			app_destroy(t_app *app)
{
	mlx_destroy_image(MLX_PTR, app->img);
	mlx_destroy_image(MLX_PTR, app->background);
	mlx_destroy_image(MLX_PTR, app->menu_l->menu_ico);
	mlx_destroy_image(MLX_PTR, app->menu_l->menu_fract);
	mlx_destroy_image(MLX_PTR, app->menu_l->menu_fract2);
	mlx_destroy_image(MLX_PTR, app->menu_l->menu_fract3);
	ft_free(app->menu_l);
	mlx_destroy_image(MLX_PTR, app->menu_b->slider_motion);
	mlx_destroy_image(MLX_PTR, app->menu_b->slider_t1);
	mlx_destroy_image(MLX_PTR, app->menu_b->slider_t2);
	mlx_destroy_image(MLX_PTR, app->menu_b->slider_t3);
	mlx_destroy_image(MLX_PTR, app->menu_b->slider_t4);
	mlx_destroy_image(MLX_PTR, app->menu_b->slider_t5);
	mlx_destroy_image(MLX_PTR, app->menu_b->phenix);
	mlx_destroy_image(MLX_PTR, app->menu_b->plus);
	mlx_destroy_image(MLX_PTR, app->menu_b->minus);
	ft_free(app->menu_b);
	ft_free(app->theme);
	ft_free(app->data);
	ft_free(app);
}
