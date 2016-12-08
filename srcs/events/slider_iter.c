/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:58:12 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/08 16:27:39 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	if_plus_iter(int x, int y, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (x >= 1815 && x <= 1850 && y >= 335 && y <= 370)
	{
		if (app->data->iter < 500)
			app->data->iter += 1;
	}
}

void	if_minus_iter(int x, int y, t_app *app)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	if (x >= 1705 && x <= 1740 && y >= 335 && y <= 370)
	{
		if (app->data->iter > 10)
			app->data->iter -= 1;
	}
}
