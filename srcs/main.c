/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:52:44 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/07 09:47:21 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_app	*app;
	int		map;

	app = NULL;
	map = 0;
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			map = 1;
		else if (!ft_strcmp(av[1], "julia"))
			map = 2;
		if (map == 1 || map == 2)
		{
			if ((start_treatment(app, map)) == -1)
				return (-1);
			app_destroy(app);
		}
		else
		{
			ft_putstr_fd(ERR2, 0);
			return (-1);
		}
	}
	else
		ft_putstr_fd(ERR1, 0);
	return (0);
}
