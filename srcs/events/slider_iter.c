/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:58:12 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/06 16:50:47 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	if_slider_iter_off(int x, int y, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (x >= 1675 && x <= 1750 && y >= 265 && y <= 300)
	{
		app->menu_b->slider_iter->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_off.xpm", &w, &h);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_b->slider_iter->img_ptr, 1670, 260);
		app->data->iter_on = 0;
	}
}

void	if_slider_iter_on(int x, int y, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (x >= 1675 && x <= 1750 && y >= 265 && y <= 300)
	{
		app->menu_b->slider_iter->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/slider_on.xpm", &w, &h);
		mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->menu_b->slider_iter->img_ptr, 1670, 260);
		app->data->iter_on = 1;
	}
}

void	if_plus_iter(int x, int y, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (app->data->iter_on == 1 &&
		x >= 1815 && x <= 1850 && y >= 335 && y <= 370)
	{
		app->data->iter += 5;
	}
}

void	if_minus_iter(int x, int y, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (app->data->iter_on == 1 &&
		x >= 1705 && x <= 1740 && y >= 335 && y <= 370)
	{
		app->data->iter -= 5;
	}
}
