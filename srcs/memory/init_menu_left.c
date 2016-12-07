/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:28:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/07 17:05:42 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_menu_l		*fill_menu_left(t_app *app, t_menu_l *tmp, int *h, int *w)
{
	if (app->burger == 0)
		tmp->menu_ico->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			"srcs/img/menu_close.xpm", w, h);
	tmp->menu_fract->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/menu_fract.xpm", w, h);
	tmp->menu_fract2->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/menu_fract.xpm", w, h);
	tmp->menu_fract3->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/menu_fract.xpm", w, h);
	return (tmp);
}

t_menu_l		*init_left_menu(t_app *app, int *h, int *w)
{
	t_menu_l	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_menu_l))))
		exit (-1);
	tmp->menu_ico = init_img(app, 64, 64);
	tmp->menu_fract = init_img(app, 320, 320);
	tmp->menu_fract2 = init_img(app, 320, 320);
	tmp->menu_fract3 = init_img(app, 320, 320);
	tmp = fill_menu_left(app, tmp, h, w);
	return (tmp);
}
