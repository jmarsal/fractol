/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_and_str_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 00:21:02 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/08 12:37:25 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_str_to_win(t_app *app)
{
	mlx_string_put(MLX_PTR, MLX_WIN, 120, 50, RED, "CHOOSE FRACTALS");
	mlx_string_put(MLX_PTR, MLX_WIN, 1740, 105, RED, "MOTION");
	mlx_string_put(MLX_PTR, MLX_WIN, 1730, 285, RED, "ITERATION");
	if (app->burger == 1)
	{
		app->bool_button.mandel == 0 ?
			mlx_string_put(MLX_PTR, MLX_WIN, 110, 138, BLUE_MENU, "MANDELBROT") :
			mlx_string_put(MLX_PTR, MLX_WIN, 110, 138, RED, "MANDELBROT");
		app->bool_button.julia == 0 ?
			mlx_string_put(MLX_PTR, MLX_WIN, 135, 230, BLUE_MENU, "JULIA") :
			mlx_string_put(MLX_PTR, MLX_WIN, 135, 230, RED, "JULIA");
		app->bool_button.bship == 0 ?
			mlx_string_put(MLX_PTR, MLX_WIN, 135, 325, BLUE_MENU, "BSHIP") :
			mlx_string_put(MLX_PTR, MLX_WIN, 135, 325, RED, "BSHIP");
		app->bool_button.sword == 0 ?
			mlx_string_put(MLX_PTR, MLX_WIN, 135, 418, BLUE_MENU, "SWORD") :
			mlx_string_put(MLX_PTR, MLX_WIN, 135, 418, RED, "SWORD");
		app->bool_button.chameleon == 0 ?
			mlx_string_put(MLX_PTR, MLX_WIN, 115, 510, BLUE_MENU, "CHAMELEON") :
			mlx_string_put(MLX_PTR, MLX_WIN, 115, 510, RED, "CHAMELEON");
		app->bool_button.tricorn == 0 ?
			mlx_string_put(MLX_PTR, MLX_WIN, 122, 606, BLUE_MENU, "TRICORN") :
			mlx_string_put(MLX_PTR, MLX_WIN, 122, 606, RED, "TRICORN");
		app->bool_button.celtic == 0 ?
			mlx_string_put(MLX_PTR, MLX_WIN, 125, 698, BLUE_MENU, "CELTIC") :
			mlx_string_put(MLX_PTR, MLX_WIN, 125, 698, RED, "CELTIC");
		app->bool_button.my_fractal == 0 ?
			mlx_string_put(MLX_PTR, MLX_WIN, 110, 790, BLUE_MENU, "MY FRACTAL") :
			mlx_string_put(MLX_PTR, MLX_WIN, 110, 790, RED, "MY FRACTAL");
		app->bool_button.exit == 0 ?
			mlx_string_put(MLX_PTR, MLX_WIN, 130, 885, PINK, "EXIT") :
			mlx_string_put(MLX_PTR, MLX_WIN, 95, 885, RED, "EXIT REALLY ??");
	}
}

void		put_img_menu_l_to_win(t_app *app, t_menu_l *tmp)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (app->burger == 1)
	{
		tmp->menu_ico->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/menu.xpm", &w, &h);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
			tmp->menu_fract->img_ptr, 0, 80);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
			tmp->menu_fract2->img_ptr, 0, 360);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
			tmp->menu_fract3->img_ptr, 0, 640);
	}
	else
		tmp->menu_ico->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/menu_close.xpm", &w, &h);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->menu_ico->img_ptr, 35, 30);
	put_str_to_win(app);
}
