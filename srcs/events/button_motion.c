/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:07:01 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/08 00:12:04 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		motion_button_activate_julia(int x, int y, t_app *app)
{
	if (x >= 30 && x <= 295 && y >= 485 && y <= 560)
	{
		init_bool(&app->bool_button);
		app->bool_button.chameleon = 1;
		refresh_win(app);
	}
	else if (x >= 30 && x <= 295 && y >= 580 && y <= 655)
	{
		init_bool(&app->bool_button);
		app->bool_button.tricorn = 1;
		refresh_win(app);
	}
	else if (x >= 30 && x <= 295 && y >= 673 && y <= 750)
	{
		init_bool(&app->bool_button);
		app->bool_button.celtic = 1;
		refresh_win(app);
	}
	else if (x >= 30 && x <= 295 && y >= 765 && y <= 840)
	{
		init_bool(&app->bool_button);
		app->bool_button.my_fractal = 1;
		refresh_win(app);
	}
	else if (x >= 30 && x <= 295 && y >= 857 && y <= 932)
	{
		init_bool(&app->bool_button);
		app->bool_button.exit = 1;
		refresh_win(app);
	}
}

void		motion_button_activate_mandel(int x, int y, t_app *app)
{
	if (x >= 30 && x <= 295 && y >= 115 && y <= 190) //bouton mandelbrot
	{
		init_bool(&app->bool_button);
		app->bool_button.mandel = 1;
		refresh_win(app);
	}
	else if (x >= 30 && x <= 295 && y >= 205 && y <= 280)
	{
		init_bool(&app->bool_button);
		app->bool_button.julia = 1;
		refresh_win(app);
	}
	else if (x >= 30 && x <= 295 && y >= 300 && y <= 375)
	{
		init_bool(&app->bool_button);
		app->bool_button.bship = 1;
		refresh_win(app);
	}
	else if (x >= 30 && x <= 295 && y >= 393 && y <= 470)
	{
		init_bool(&app->bool_button);
		app->bool_button.sword = 1;
		refresh_win(app);
	}
}

void		motion_button_desactivate(t_app *app)
{
	init_bool(&app->bool_button);
}
