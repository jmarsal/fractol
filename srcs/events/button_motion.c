/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:07:01 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/06 16:01:08 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		motion_button_activate_julia(int x, int y, t_app *app)
{
	int			w;
	int			h;
	
	w = WIDTH;
	h = HEIGHT;
	if (x >= 30 && x <= 295 && y >= 210 && y <= 285) //bouton julia
	{
		app->menu_l->mandel_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/mandelbrot_blue.xpm", &w, &h);
		app->menu_l->julia_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/julia_red.xpm", &w, &h);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_l->julia_col->img_ptr, 105, 198);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_l->mandel_col->img_ptr, 70, 105);
	}
}

void		motion_button_activate_mandel(int x, int y, t_app *app)
{
	int			w;
	int			h;
	
	w = WIDTH;
	h = HEIGHT;
	if (x >= 30 && x <= 295 && y >= 115 && y <= 190) //bouton mandelbrot
	{
		app->menu_l->julia_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/julia_blue.xpm", &w, &h);
		app->menu_l->mandel_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/mandelbrot_red.xpm", &w, &h);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_l->mandel_col->img_ptr, 70, 105);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_l->julia_col->img_ptr, 105, 198);
	}
}

void		motion_button_desactivate(t_app *app)
{
	int			w;
	int			h;
	
	w = WIDTH;
	h = HEIGHT;
	app->menu_l->mandel_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/mandelbrot_blue.xpm", &w, &h);
	app->menu_l->julia_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/julia_blue.xpm", &w, &h);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
	app->menu_l->mandel_col->img_ptr, 70, 105);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
	app->menu_l->julia_col->img_ptr, 105, 198);
}
