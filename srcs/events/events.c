/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:01:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/08 16:13:21 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		mouse_motion_fract(int x, int y, t_app *app)
{
	static int	tmp_x;
	static int	tmp_y;
	
	if (app->data->motion == 1)//motion
	{
		if (x > 350 && x < WIDTH_DRAW + 350 && y > 100 && y < HEIGHT_DRAW + 100)
		{
			x -= 350;
			y -= 100;
			if (x < WIDTH_DRAW && y < HEIGHT_DRAW)
			{
				if (x > tmp_x)
					app->data->c_r += 0.05;
				else
					app->data->c_r -= 0.05;
				if (y > tmp_y)
					app->data->c_i += 0.05;
				else
					app->data->c_i -= 0.05;
			}
			tmp_x = x;
			tmp_y = y;
		}
	}
}



int				mouse_motion_menu(int x, int y, t_app *app)
{
	mouse_motion_fract(x, y, app);
	//bouton mandelbrot
	if (x >= 30 && x <= 295 && y >= 115 && y <= 932)
	{
		motion_button_activate(x, y, app);
		motion_button_activate2(x, y, app);
	}
	else
		motion_button_desactivate(app);
	refresh_win(app);
	return (0);
}

int				key_funct(int keycode, t_app *app)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == LEFT || keycode == RIGHT || keycode == UP\
			|| keycode == DOWN)
		move_tray(keycode, app);
	if (keycode == ORIGIN)
		origin(keycode, app);
	return (0);
}
