/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:01:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/06 09:45:19 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
# include <stdio.h>

// int				mouse_motion_fract(int x, int y, t_app *app)
// {
	
// 	return (0);
// }

int				mouse_motion_menu(int x, int y, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (app->data->motion == 1)//motion
	{
		// printf("x = %d, y = %d, motion = %d\n", x, y, app->data->motion);		
		if (x > 350 && x < WIDTH_DRAW + 350 && y > 100 && y < HEIGHT_DRAW + 100)
		{
			x -= 350;
			y -= 100;
			if (x < WIDTH_DRAW / 2 && y < HEIGHT_DRAW / 2)
				app->data->c_r += 0.05;
			if (x > WIDTH_DRAW / 2 && y < HEIGHT_DRAW / 2)
				app->data->c_r -= 0.05;
			if (x < WIDTH_DRAW / 2 && y > HEIGHT_DRAW / 2)
				app->data->c_i += 0.05;
			if (x > WIDTH_DRAW / 2 && y > HEIGHT_DRAW / 2)
				app->data->c_i -= 0.05;
		}
		refresh_win(app);
	}
	if (x >= 30 && x <= 295 && y >= 115 && y <= 190) //bouton mandelbrot
	{
		mlx_destroy_image(MLX_PTR, app->menu_l->mandel_col);
		app->menu_l->mandel_col = init_img(app, WIDTH_DRAW, HEIGHT_DRAW);
		app->menu_l->mandel_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/mandelbrot_red.xpm", &w, &h);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_l->mandel_col->img_ptr, 70, 105);
	}
	else if (x >= 30 && x <= 295 && y >= 210 && y <= 285) //bouton julia
	{
		mlx_destroy_image(MLX_PTR, app->menu_l->julia_col);
		app->menu_l->julia_col = init_img(app, WIDTH_DRAW, HEIGHT_DRAW);
		app->menu_l->julia_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/julia_red.xpm", &w, &h);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_l->julia_col->img_ptr, 105, 198);
	}
	else
	{
		mlx_destroy_image(MLX_PTR, app->menu_l->mandel_col);
		app->menu_l->mandel_col = init_img(app, WIDTH_DRAW, HEIGHT_DRAW);
		app->menu_l->mandel_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/mandelbrot_blue.xpm", &w, &h);
		mlx_destroy_image(MLX_PTR, app->menu_l->julia_col);
		app->menu_l->julia_col = init_img(app, WIDTH_DRAW, HEIGHT_DRAW);
		app->menu_l->julia_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/julia_blue.xpm", &w, &h);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_l->mandel_col->img_ptr, 70, 105);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_l->julia_col->img_ptr, 105, 198);
	}
	// refresh_win(app);	
	return (0);
}

int				mouse_funct(int button, int x, int y, t_app *app)
{
	double	mouse_x_pos;
	double	mouse_y_pos;
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
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
		refresh_win(app);
	}
	if (x >= 30 && x <= 295 && y >= 115 && y <= 190) // bouton mandelbrot
	{
		// app_destroy(app);
		app->mapname = 1;
		refresh_win(app);
		// mlx_destroy_image(MLX_PTR, app->img);
		// start_treatment(app, 1);
	}
	else if (x >= 30 && x <= 295 && y >= 205 && y <= 280) // bouton julia
	{
		// app_destroy(app);
		app->mapname = 2;
		refresh_win(app);
		// mlx_destroy_image(MLX_PTR, app->img);
		// start_treatment(app, 2);
	}
	else if (app->data->motion == 0 &&
		x >= 1675 && x <= 1750 && y >= 165 && y <= 200)
	{
		mlx_destroy_image(MLX_PTR, app->menu_b->slider_motion);
		app->menu_b->slider_motion = init_img(app, WIDTH_DRAW, HEIGHT_DRAW);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", &w, &h);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_b->slider_motion->img_ptr, 1670, 160);
		app->data->motion = 1;
	}
	else if (app->data->motion == 1 &&
		x >= 1675 && x <= 1750 && y >= 165 && y <= 200)
	{
		mlx_destroy_image(MLX_PTR, app->menu_b->slider_motion);
		app->menu_b->slider_motion = init_img(app, WIDTH_DRAW, HEIGHT_DRAW);
		app->menu_b->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_b->slider_motion->img_ptr, 1670, 160);
		app->data->motion = 0;
	}
	(void)button;
	return (0);
}

int				key_funct(int keycode, t_app *app)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == LEFT || keycode == RIGHT || keycode == UP\
			|| keycode == DOWN)
		move_tray(keycode, app);
	if (keycode == ORIGIN)
		origin(keycode, app);
	return (0);
}
