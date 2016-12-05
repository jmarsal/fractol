/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:01:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/05 09:49:05 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
