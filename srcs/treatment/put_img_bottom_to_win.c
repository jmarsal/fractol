/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_bottom_to_win.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:57:56 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 11:29:14 by jmarsal          ###   ########.fr       */
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
	mlx_string_put(MLX_PTR, MLX_WIN, 820, 930, RED, PARAMETERS);
	if (app->burger == 0)
	{
		mlx_string_put(MLX_PTR, MLX_WIN, 55, 200, RED, "NOTICE :");
		mlx_string_put(MLX_PTR, MLX_WIN, 35, 250, 0xAEECFE, SCROLL);
		mlx_string_put(MLX_PTR, MLX_WIN, 35, 280, 0xAEECFE, ARROWS);
		mlx_string_put(MLX_PTR, MLX_WIN, 55, 310, 0xAEECFE, "on the tray");
		mlx_string_put(MLX_PTR, MLX_WIN, 105, 700, 0xAEECFE, "fractol made by");
		mlx_string_put(MLX_PTR, MLX_WIN, 105, 730, 0xAEECFE, AUTEUR);
		mlx_string_put(MLX_PTR, MLX_WIN, 35, 770, 0xFFFFFF,
													"jmarsal@student.42.fr");
		mlx_string_put(MLX_PTR, MLX_WIN, 35, 800, 0xFFFFFF,
												"https://github.com/jmarsal");
		mlx_string_put(MLX_PTR, MLX_WIN, 35, 830, 0xFFFFFF, "December 2016");
	}
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
	if (app->burger == 0)
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
			tmp->phenix->img_ptr, 35, 700);
	fill_text(app);
}
