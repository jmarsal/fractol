/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:10:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/08 23:22:51 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			motion_button_activate3(int x, int y, t_app *app)
{
	if (x >= 1675 && x <= 1747 && y >= 555 && y <= 585)
	{
		app->theme = init_theme();
		app->theme->t1_on = 1;
	}
	else if (x >= 1675 && x <= 1747 && y >= 605 && y <= 635)
	{
		app->theme = init_theme();
		app->theme->t2_on = 1;
	}
	else if (x >= 1675 && x <= 1747 && y >= 655 && y <= 685)
	{
		app->theme = init_theme();
		app->theme->t3_on = 1;
	}
	else if (x >= 1675 && x <= 1747 && y >= 705 && y <= 735)
	{
		app->theme = init_theme();
		app->theme->t4_on = 1;
	}
	else if (x >= 1675 && x <= 1747 && y >= 755 && y <= 785)
	{
		app->theme = init_theme();
		app->theme->t5_on = 1;
	}
}

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
		app->data = init_coords_mandelbrot(app);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 205 && y <= 280) // bouton julia
	{
		app->mapname = 2;
		app->fractal = "JULIA";
		app->data = init_julia(app);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	}
	else if (x >= 30 && x <= 295 && y >= 300 && y <= 375)
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
	else if (x >= 30 && x <= 295 && y >= 485 && y <= 560)
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
	else if (x >= 30 && x <= 295 && y >= 673 && y <= 750)
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

static void		if_slider_motion(int x, int y, int button, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (app->data->motion == 1 &&
		((x >= 1735 && x <= 1810 && y >= 145 && y <= 177) || (button == 2)))
	{
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		app->data->motion = 0;
	}
	else if (app->data->motion == 0 &&
		((x >= 1735 && x <= 1810 && y >= 145 && y <= 177) || (button == 2)))
	{
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", &w, &h);
		app->data->motion = 1;
	}
}

static void		put_newpos_of_slider_theme(t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (app->theme->t1_on == 1)
		app->menu_b->slider_t1->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", &w, &h);
	else
		app->menu_b->slider_t1->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	if (app->theme->t2_on == 1)
		app->menu_b->slider_t2->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", &w, &h);
	else
		app->menu_b->slider_t2->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	
	if (app->theme->t3_on == 1)
		app->menu_b->slider_t3->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", &w, &h);
	else
		app->menu_b->slider_t3->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);

	if (app->theme->t4_on == 1)
		app->menu_b->slider_t4->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", &w, &h);
	else
		app->menu_b->slider_t4->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);

	if (app->theme->t5_on == 1)
		app->menu_b->slider_t5->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", &w, &h);
	else
		app->menu_b->slider_t5->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
	
}

int				mouse_funct(int button, int x, int y, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if_zoom(x, y, button, app);
	if_slider_motion(x, y, button, app);
	if_plus_iter(x, y, app);
	if_minus_iter(x, y, app);
	mlx_string_put(MLX_PTR, MLX_WIN, 1760, 338, ORANGE,
		ft_itoa_base((long)app->data->iter, 10));
	if_clic_button(x, y, app);
	motion_button_activate3(x, y, app);
	put_newpos_of_slider_theme(app);
	refresh_win(app);
	return (0);
}
