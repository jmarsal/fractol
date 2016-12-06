/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:51:56 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/06 16:36:03 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_menu_b	*fill_menu_bottom(t_app *app, t_menu_b *tmp, int *h, int *w)
{
	tmp->slider_motion->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/slider_off.xpm", w, h);
	tmp->slider_iter->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/slider_off.xpm", w, h);
	tmp->plus->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/plus.xpm", w, h);
	tmp->minus->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/minus.xpm", w, h);
	return (tmp);
}

t_menu_b		*init_bottom_menu(t_app *app, int *h, int *w)
{
	t_menu_b	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_menu_b))))
		exit (-1);
	tmp->slider_motion = init_img(app, 64, 64);
	tmp->slider_iter = init_img(app, 64, 64);
	tmp->plus = init_img(app, 64, 64);
	tmp->minus = init_img(app, 64, 64);
	tmp = fill_menu_bottom(app, tmp, h, w);
	return (tmp);
}
