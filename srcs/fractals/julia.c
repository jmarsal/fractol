/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 00:31:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/07 23:54:02 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data		*init_julia(void)
{
	t_data *data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data->iter = 100;
	data->iter_on = 0;
	data->motion = 0;
	data->x1 = -1.95;
	data->y1 = -1.95;
	data->zoom = 204;
	data->c_r = 0.285;
	data->c_i = 0.01;
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
		if (app->mapname == 7)
			app->data->z_r = fabs(app->data->z_r * app->data->z_r -
				app->data->z_i * app->data->z_i + app->data->c_r);
		else if (app->mapname == 8)
			app->data->z_r = fabs(app->data->z_r * app->data->z_r -
				app->data->z_i * app->data->z_i) + app->data->c_r;
		else
			app->data->z_r = app->data->z_r * app->data->z_r -
				app->data->z_i * app->data->z_i + app->data->c_r;
		if (app->mapname == 6 || app->mapname == 8)
			app->data->z_i = -2 * app->data->z_i *
				app->data->tmp + app->data->c_i;
		else if (app->mapname == 7)
			app->data->z_i = fabs(2 * app->data->z_i *
				app->data->tmp + app->data->c_i);
		else
			app->data->z_i = 2 * app->data->z_i *
				app->data->tmp + app->data->c_i;
		app->data->i++;
	}
	put_pixel_and_choose_color(app);
}

static void	get_data(t_app *app)
{
	while (app->data->y < HEIGHT_DRAW)
		{
			app->data->z_r = app->data->x / app->data->zoom + app->data->x1;
			app->data->z_i = app->data->y / app->data->zoom + app->data->y1;
			app->data->i = 0;
			get_data_result(app);
			app->data->y++;
		}
}

void		draw_julia(t_app *app)
{
	while (app->data->x < WIDTH_DRAW)
	{
		app->data->y = 0;
		get_data(app);
		app->data->x++;
	}
	app->data->x = 0;
}
