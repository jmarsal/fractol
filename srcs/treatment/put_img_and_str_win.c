/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_and_str_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 00:21:02 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/07 17:06:22 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_str_to_win(t_app *app)
{
	mlx_string_put(MLX_PTR, MLX_WIN, 120, 50, RED, "CHOOSE FRACTALS");
	mlx_string_put(MLX_PTR, MLX_WIN, 1755, 168, RED, "Motion");
	mlx_string_put(MLX_PTR, MLX_WIN, 1755, 268, RED, "Iteration");
	if (app->burger == 1)
	{
		if (app->bool_button.mandel == 0)
			mlx_string_put(MLX_PTR, MLX_WIN, 110, 136, BLUE_MENU, "MANDELBROT");
		else
			mlx_string_put(MLX_PTR, MLX_WIN, 110, 136, RED, "MANDELBROT");
		if (app->bool_button.julia == 0)
			mlx_string_put(MLX_PTR, MLX_WIN, 135, 230, BLUE_MENU, "JULIA");
		else
			mlx_string_put(MLX_PTR, MLX_WIN, 135, 230, RED, "JULIA");
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
