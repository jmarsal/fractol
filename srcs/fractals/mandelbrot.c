/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:23:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/05 09:42:30 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*init_coords_mandelbrot(void)
{
	t_data *data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (NULL);
	data->iter = 150;
	// data->mouse_pos = 0;
	data->x1 = -2.02;
	data->x2 = 0.6;
	data->y1 = -2.02;
	data->y2 = 1.2;
	data->zoom = 100;
	data->color = PINK;
	data->x = 0;
	data->y = 0;
	return (data);
}

static void get_data_result(t_app *app)
{
	while ((app->data->z_r * app->data->z_r + app->data->z_i * app->data->z_i)
		< 4 && app->data->i < app->data->iter)
	{
		app->data->tmp = app->data->z_r;
		app->data->z_r = app->data->z_r * app->data->z_r - app->data->z_i *
			app->data->z_i + app->data->c_r;
		app->data->z_i = 2 * app->data->z_i * app->data->tmp + app->data->c_i;
		app->data->i++;
	}
	put_pixel_and_choose_color(app);
}

static void	get_data(t_app *app)
{
	while (app->data->y < HEIGHT_DRAW)
		{
			app->data->c_r = app->data->x / app->data->zoom + app->data->x1;
			app->data->c_i = app->data->y / app->data->zoom + app->data->y1;
			app->data->z_r = 0;
			app->data->z_i = 0;
			app->data->i = 0;
			get_data_result(app);
			app->data->y++;
		}
}

void		draw_mandelbrot(t_app *app)
{
	while (app->data->x < WIDTH_DRAW)
	{
		app->data->y = 0;
		get_data(app);
		app->data->x++;
	}
	app->data->x = 0;
}
