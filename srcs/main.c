/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:52:44 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/08 00:04:02 by jmarsal          ###   ########.fr       */
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
		else if (!ft_strcmp(av[1], "bship"))
			map = 3;
		else if (!ft_strcmp(av[1], "tricorn"))
			map = 4;
		else if (!ft_strcmp(av[1], "celtic"))
			map = 5;
		else if (!ft_strcmp(av[1], "chameleon"))
			map = 6;
		else if (!ft_strcmp(av[1], "sword"))
			map = 7;
		else if (!ft_strcmp(av[1], "my_fractal"))
			map = 8;
		if (map >= 1 && map <= 8)
		{
			if ((start_treatment(app, map, av[1])) == -1)
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
