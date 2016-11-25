/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:52:44 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/25 16:51:58 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fract	*env;

	env = NULL;
	if (ac == 2)
	{
		if (!(env = ft_memalloc(sizeof(t_fract))))
			return (-1);
		if (!ft_strcmp(av[1], "mandelbrot"))
		{
			if ((start_treatment(env, av[1])) == -1)
				return (-1);
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
