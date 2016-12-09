/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_img_sliders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 09:47:00 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 09:48:11 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_newpos_of_slider_theme_part_2(t_app *app, int *w, int *h)
{
	if (app->theme->t3_on == 1)
		app->menu_b->slider_t3->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", w, h);
	else
		app->menu_b->slider_t3->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", w, h);
	if (app->theme->t4_on == 1)
		app->menu_b->slider_t4->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", w, h);
	else
		app->menu_b->slider_t4->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", w, h);
	if (app->theme->t5_on == 1)
		app->menu_b->slider_t5->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", w, h);
	else
		app->menu_b->slider_t5->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", w, h);
}

void		put_newpos_of_slider_theme(t_app *app)
{
	int	w;
	int	h;

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
	put_newpos_of_slider_theme_part_2(app, &w, &h);
}
