/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:23:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/08 14:41:04 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_color_on(t_app *app, int color)
{
	
	if (app->theme->t1_on == 1)
		color = app->theme->t1;
	else if (app->theme->t2_on == 1)
		color = app->theme->t2;
	else if (app->theme->t3_on == 1)
		color = app->theme->t3;
	else if (app->theme->t4_on == 1)
		color = app->theme->t4;
	else
		color = app->theme->t5;
	return (color);
}

t_data	*init_coords_mandelbrot(t_app *app)
{
	t_data *data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (NULL);
	data->iter = 125;
	data->motion = 0;
	data->x1 = -2.02;
	data->x2 = 0.6;
	data->y1 = -2.02;
	data->y2 = 1.2;
	data->zoom = 210;
	data->color = check_color_on(app, data->color);
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
		if (app->mapname == 3)
			app->data->z_r = fabs(app->data->z_r * app->data->z_r -
				app->data->z_i * app->data->z_i + app->data->c_r);
		else if (app->mapname == 5)
			app->data->z_r = fabs(app->data->z_r * app->data->z_r -
				app->data->z_i * app->data->z_i) + app->data->c_r;
		else
			app->data->z_r = app->data->z_r * app->data->z_r - app->data->z_i *
				app->data->z_i + app->data->c_r;
		if (app->mapname == 3)
			app->data->z_i = fabs(2 * app->data->z_i *
				app->data->tmp + app->data->c_i);
		else if (app->mapname == 4)
			app->data->z_i = -2 * app->data->z_i *
				app->data->tmp + app->data->c_i;
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
