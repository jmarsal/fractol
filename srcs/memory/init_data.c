/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:38:37 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 09:52:29 by jmarsal          ###   ########.fr       */
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
