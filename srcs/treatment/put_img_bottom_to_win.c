/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_bottom_to_win.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:57:56 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/05 22:50:53 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_img_menu_b_to_win(t_app *app, t_menu_b *tmp)
{
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		tmp->slider_motion->img_ptr, 1670, 160);
}
