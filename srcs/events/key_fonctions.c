/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:10:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 11:48:26 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			origin(int keycode, t_app *app)
{
	if (keycode == ORIGIN)
	{
		if (app->mapname == 1 || app->mapname == 3 ||
			app->mapname == 4 || app->mapname == 5)
			app->data = init_coords_mandelbrot(app);
		else
			app->data = init_julia(app);
		refresh_win(app);
	}
}

static double	progressive_i(t_app *app)
{
	static double	i;

	i = 0.2;
	if (app->data->zoom <= 100)
		i = 0.2;
	if (app->data->zoom > 100 && app->data->zoom <= 1000)
		i = 0.02;
	if (app->data->zoom > 1000 && app->data->zoom <= 10000)
		i = 0.002;
	if (app->data->zoom > 10000 && app->data->zoom <= 100000)
		i = 0.0002;
	if (app->data->zoom > 100000)
		i = 0.00002;
	return (i);
}

void			move_tray(int keycode, t_app *app)
{
	double	i;

	i = progressive_i(app);
	if (keycode == LEFT)
		app->data->x1 += i;
	else if (keycode == RIGHT)
		app->data->x1 -= i;
	else if (keycode == DOWN)
		app->data->y1 += i;
	else if (keycode == UP)
		app->data->y1 -= i;
	refresh_win(app);
}
