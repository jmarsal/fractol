/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_bottom_to_win.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:57:56 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/08 16:23:24 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_text(t_app *app)
{
	mlx_string_put(MLX_PTR, MLX_WIN, 1720, 500, RED, "CHANGE THEME");
	mlx_string_put(MLX_PTR, MLX_WIN, 1775, 555, PINK, "PINK");
	mlx_string_put(MLX_PTR, MLX_WIN, 1765, 605, YELLOW, "YELLOW");
	mlx_string_put(MLX_PTR, MLX_WIN, 1778, 657, RED, "RED");
	mlx_string_put(MLX_PTR, MLX_WIN, 1765, 707, ORANGE, "ORANGE");
	mlx_string_put(MLX_PTR, MLX_WIN, 1770, 757, BLUE, "BLUE");
}

void		put_img_menu_b_to_win(t_app *app, t_menu_b *tmp)
{
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->slider_motion->img_ptr, 1730, 140);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->slider_t1->img_ptr, 1670, 550);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->slider_t2->img_ptr, 1670, 600);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->slider_t3->img_ptr, 1670, 650);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->slider_t4->img_ptr, 1670, 700);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->slider_t5->img_ptr, 1670, 750);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->minus->img_ptr, 1705, 335);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->plus->img_ptr, 1815, 335);
	fill_text(app);
}
