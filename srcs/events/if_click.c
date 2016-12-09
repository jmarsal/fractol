/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_click.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 09:42:23 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 11:44:59 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	if_clic_button5(int x, int y, t_app *app)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	if (x >= 40 && x <= 100 && y >= 40 && y <= 90)
	{
		if (app->burger == 0)
			app->burger = 1;
		else
			app->burger = 0;
	}
}

static void	if_clic_button4(int x, int y, t_app *app)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	if (x >= 30 && x <= 295 && y >= 673 && y <= 750)
	{
		app->mapname = 5;
		app->fractal = "CELTIC";
		app->data = init_coords_mandelbrot(app);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 765 && y <= 840)
	{
		app->mapname = 8;
		app->fractal = "MY_FRACTAL";
		app->data = init_julia(app);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 857 && y <= 932)
		close_win(app);
}

static void	if_clic_button3(int x, int y, t_app *app)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	if (x >= 30 && x <= 295 && y >= 485 && y <= 560)
	{
		app->mapname = 6;
		app->fractal = "CHAMELEON";
		app->data = init_julia(app);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 580 && y <= 655)
	{
		app->mapname = 4;
		app->fractal = "TRICORN";
		app->data = init_coords_mandelbrot(app);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	if_clic_button4(x, y, app);
}

static void	if_clic_button2(int x, int y, t_app *app)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	if (x >= 30 && x <= 295 && y >= 300 && y <= 375)
	{
		app->mapname = 3;
		app->fractal = "BSHIP";
		app->data = init_coords_mandelbrot(app);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 393 && y <= 470)
	{
		app->mapname = 7;
		app->fractal = "SWORD";
		app->data = init_julia(app);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	if_clic_button3(x, y, app);
}

void		if_clic_button(int x, int y, t_app *app)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	if_clic_button5(x, y, app);
	if (app->burger == 1 && x >= 30 && x <= 295 && y >= 115 && y <= 190)
	{
		app->mapname = 1;
		app->fractal = "MANDELBROT";
		app->data = init_coords_mandelbrot(app);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (app->burger == 1 && x >= 30 && x <= 295 && y >= 205 && y <= 280)
	{
		app->mapname = 2;
		app->fractal = "JULIA";
		app->data = init_julia(app);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	if (app->burger == 1)
		if_clic_button2(x, y, app);
}
