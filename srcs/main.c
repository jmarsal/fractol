/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:52:44 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 11:53:09 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	map_return(char *fractal)
{
	int	map;

	map = 0;
	if (!ft_strcmp(fractal, "mandelbrot"))
		map = 1;
	else if (!ft_strcmp(fractal, "julia"))
		map = 2;
	else if (!ft_strcmp(fractal, "bship"))
		map = 3;
	else if (!ft_strcmp(fractal, "tricorn"))
		map = 4;
	else if (!ft_strcmp(fractal, "celtic"))
		map = 5;
	else if (!ft_strcmp(fractal, "chameleon"))
		map = 6;
	else if (!ft_strcmp(fractal, "sword"))
		map = 7;
	else if (!ft_strcmp(fractal, "my_fractal"))
		map = 8;
	else if (!ft_strcmp(fractal, "help"))
		map = 9;
	return (map);
}

static int	search_errors(char *av)
{
	int	test;

	test = map_return(av);
	if (test == 0 || test == 9)
	{
		test == 9 ? ft_putstr_fd(HELP, 0) : ft_putstr_fd(ERR1, 0);
		return (-1);
	}
	return (test);
}

int			main(int ac, char **av)
{
	t_app	*app;
	int		map;

	app = NULL;
	map = 0;
	if (ac == 2)
	{
		if ((map = search_errors(av[1])) == -1)
			return (-1);
		if ((start_treatment(app, map, av[1])) == -1)
			return (-1);
		app_destroy(app);
	}
	else
		ft_putstr_fd(ERR1, 0);
	return (0);
}
