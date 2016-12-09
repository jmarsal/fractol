/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:38:37 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 11:19:21 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_bool(t_bool *bool_button)
{
	bool_button->mandel = 0;
	bool_button->julia = 0;
	bool_button->bship = 0;
	bool_button->sword = 0;
	bool_button->chameleon = 0;
	bool_button->tricorn = 0;
	bool_button->celtic = 0;
	bool_button->my_fractal = 0;
	bool_button->exit = 0;
}

t_theme	*init_theme(void)
{
	t_theme	*theme;

	theme = ft_memalloc(sizeof(t_theme));
	theme->t1 = PINK;
	theme->t1_on = 0;
	theme->t2 = YELLOW;
	theme->t2_on = 0;
	theme->t3 = RED;
	theme->t3_on = 0;
	theme->t4 = ORANGE;
	theme->t4_on = 0;
	theme->t5 = BLUE_MENU;
	theme->t5_on = 0;
	return (theme);
}

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
