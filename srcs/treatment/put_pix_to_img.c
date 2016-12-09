/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pix_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:31:58 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 11:32:33 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mlx_put_pixel_to_image(t_app *app, int x, int y, int color)
{
	int octet;

	octet = app->img->bpp / 8;
	if (x > 0 && x < WIDTH_DRAW && y > 0 && y < HEIGHT_DRAW)
		ft_memcpy(&app->img->data[octet * (x + app->img->sizeline /
										octet * y)], &color, octet);
}

static int	find_color_in_struct(t_app *app)
{
	int	color;

	color = 0;
	if (app->theme->t1_on == 1)
		return (color = app->theme->t1);
	else if (app->theme->t2_on == 1)
		return (color = app->theme->t2);
	else if (app->theme->t3_on == 1)
		return (color = app->theme->t3);
	else if (app->theme->t4_on == 1)
		return (color = app->theme->t4);
	else
		return (color = app->theme->t5);
}

void		put_pixel_and_choose_color(t_app *app)
{
	int	color;

	color = find_color_in_struct(app);
	if (app->data->i == app->data->iter)
		mlx_put_pixel_to_image(app, app->data->x, app->data->y, color);
	else
		mlx_put_pixel_to_image(app, app->data->x, app->data->y,
			app->data->color * app->data->i / app->data->iter);
}
