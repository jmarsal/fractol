/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:10:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/08 00:17:50 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		if_clic_button(int x, int y, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (x >= 30 && x <= 295 && y >= 115 && y <= 190) // bouton mandelbrot
	{
		app->mapname = 1;
		app->fractal = "MANDELBROT";
		app->data = init_coords_mandelbrot();
		app->menu_b->slider_iter->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 205 && y <= 280) // bouton julia
	{
		app->mapname = 2;
		app->fractal = "JULIA";
		app->data = init_julia();
		app->menu_b->slider_iter->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 300 && y <= 375)
	{
		app->mapname = 3;
		app->fractal = "BSHIP";
		app->data = init_coords_mandelbrot();
		app->menu_b->slider_iter->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 393 && y <= 470)
	{
		app->mapname = 7;
		app->fractal = "SWORD";
		app->data = init_julia();
		app->menu_b->slider_iter->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 485 && y <= 560)
	{
		app->mapname = 6;
		app->fractal = "CHAMELEON";
		app->data = init_julia();
		app->menu_b->slider_iter->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 580 && y <= 655)
	{
		app->mapname = 4;
		app->fractal = "TRICORN";
		app->data = init_coords_mandelbrot();
		app->menu_b->slider_iter->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 673 && y <= 750)
	{
		app->mapname = 5;
		app->fractal = "CELTIC";
		app->data = init_coords_mandelbrot();
		app->menu_b->slider_iter->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 765 && y <= 840)
	{
		app->mapname = 8;
		app->fractal = "TEST";
		app->data = init_julia();
		app->menu_b->slider_iter->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 857 && y <= 932)
		close_win(app);
	else if (x >= 40 && x <= 100 && y >= 40 && y <= 90)
	{
		if (app->burger == 0)
			app->burger = 1;
		else
			app->burger = 0;
	}
}

static void		if_zoom(int x, int y, int button, t_app *app)
{
	double	mouse_x_pos;
	double	mouse_y_pos;

	if (x > 350 && x < WIDTH_DRAW + 350 && y > 100 && y < HEIGHT_DRAW + 100) //ZOOM
	{
		x -= 350;
		y -= 100;
		mouse_x_pos = (x / app->data->zoom) + app->data->x1;
		mouse_y_pos = (y / app->data->zoom) + app->data->y1;
		if (button == ZOOMUP)
		{
			app->data->zoom *= 1.1;
			app->data->x1 = mouse_x_pos - (x / app->data->zoom);
			app->data->y1 = mouse_y_pos - (y / app->data->zoom);
		}
		if (button == ZOOMDOWN)
		{
			app->data->zoom /= 1.1;
			app->data->x1 = mouse_x_pos - (x / app->data->zoom);
			app->data->y1 = mouse_y_pos - (y / app->data->zoom);
		}
	}
}

static void		if_slider_motion_off(int x, int y, int button, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (app->data->motion == 1 &&
		((x >= 1675 && x <= 1750 && y >= 165 && y <= 200) || (button == 2)))
	{
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		app->data->motion = 0;
	}
}

static void		if_slider_motion_on(int x, int y, int button, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (app->data->motion == 0 &&
		((x >= 1675 && x <= 1750 && y >= 165 && y <= 200) || (button == 2)))
	{
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", &w, &h);
		app->data->motion = 1;
	}
}

int				mouse_funct(int button, int x, int y, t_app *app)
{
	if_zoom(x, y, button, app);
	if (app->data->motion == 1)
		if_slider_motion_off(x, y, button, app);
	else if (app->data->motion == 0)
		if_slider_motion_on(x, y, button, app);
	if (app->data->iter_on == 1)
		if_slider_iter_off(x, y, app);
	else if (app->data->iter_on == 0)
		if_slider_iter_on(x, y, app);
	if_plus_iter(x, y, app);
	if_minus_iter(x, y, app);
	mlx_string_put(MLX_PTR, MLX_WIN, 1760, 338, ORANGE,
		ft_itoa_base((long)app->data->iter, 10));
	if_clic_button(x, y, app);
	refresh_win(app);
	return (0);
}
