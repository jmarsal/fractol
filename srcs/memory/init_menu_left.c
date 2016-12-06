/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:28:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/05 18:07:40 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_menu_l	*fill_menu_left(t_app *app, t_menu_l *tmp, int *h, int *w)
{
	tmp->menu_ico->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/menu.xpm", w, h);
	tmp->one->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/number1.xpm", w, h);
	tmp->two->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/number2.xpm", w, h);
	tmp->three->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/number3.xpm", w, h);
	tmp->mandel_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/mandelbrot_blue.xpm", w, h);
	tmp->julia_col->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
	"srcs/img/julia_blue.xpm", w, h);
	tmp->button_grey->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/button_grey.xpm", w, h);
	return (tmp);
}

t_menu_l		*init_left_menu(t_app *app, int *h, int *w)
{
	t_menu_l	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_menu_l))))
		exit (-1);
	tmp->menu_ico = init_img(app, 64, 64);
	tmp->button_grey = init_img(app, 320, 320);
	tmp->mandel_col = init_img(app, WIDTH, HEIGHT);
	tmp->julia_col = init_img(app, WIDTH, HEIGHT);
	tmp->one = init_img(app, 32, 32);
	tmp->two = init_img(app, 32, 32);
	tmp->three = init_img(app, 32, 32);
	tmp = fill_menu_left(app, tmp, h, w);
	return (tmp);
}
