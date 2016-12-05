/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:10:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/05 12:25:43 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	origin(int keycode, t_app *app)
{
	if (keycode == ORIGIN)
	{
		if (app->mapname == 1)
			app->data = init_coords_mandelbrot();
		refresh_win(app);
	}
}

void			move_tray(int keycode, t_app *app)
{
	if (keycode == LEFT)
		app->data->x1 += 0.05;
	else if (keycode == RIGHT)
		app->data->x1 -= 0.05;
	else if (keycode == DOWN)
		app->data->y1 += 0.05;
	else if (keycode == UP)
		app->data->y1 -= 0.05;
	refresh_win(app);
}
