/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_and_str_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 00:21:02 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/05 15:51:33 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_str_to_win(t_app *app)
{
	mlx_string_put(MLX_PTR, MLX_WIN, 120, 50, RED, "CHOOSE FRACTALS");
	// mlx_string_put(MLX_PTR, MLX_WIN, 120, 135, MOUSE_OFF, "MANDELBROT");
	// mlx_string_put(MLX_PTR, MLX_WIN, 135, 230, MOUSE_OFF, "JULIA");
}

void		put_img_menu_l_to_win(t_app *app, t_menu_l *tmp)
{
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->button_grey->img_ptr, 0, 80);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->menu_ico->img_ptr, 35, 30);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->one->img_ptr, 45, 130);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->two->img_ptr, 45, 225);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->three->img_ptr, 45, 320);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->mandel_col->img_ptr, 70, 105);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->julia_col->img_ptr, 105, 198);
	put_str_to_win(app);
}
