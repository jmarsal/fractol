/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:01:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/05 16:04:19 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int				mouse_motion_menu(int x, int y, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (x >= 30 && x <= 295 && y >= 115 && y <= 190)
	{
		mlx_destroy_image(MLX_PTR, app->menu_l->mandel_col);
		app->menu_l->mandel_col = init_img(app, WIDTH_DRAW, HEIGHT_DRAW);
		app->menu_l->mandel_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/mandelbrot_red.xpm", &w, &h);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_l->mandel_col->img_ptr, 70, 105);
	}
	else if (x >= 30 && x <= 295 && y >= 210 && y <= 285)
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
	return (0);
}

int				mouse_funct(int button, int x, int y, t_app *app)
{
	printf("button = %d, x = %d, y = %d\n", button, x, y);
	if (x >= 30 && x <= 295 && y >= 115 && y <= 190)
	{
		app->data = init_coords_mandelbrot();
		refresh_win(app);
	}
	// else
	// {
	// 	mlx_string_put(MLX_PTR, MLX_WIN, 120, 135, RED, "MANDELBROT");
	// 	*test = 0;
	// }
	// refresh_win(app);
	(void)y;
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
