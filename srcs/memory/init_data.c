/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:38:37 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/02 16:50:46 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO : init_data a finir

t_data	*init_coords_mandelbrot(void)
{
	t_data *data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		return (NULL);
	data->iter = 100;
	data->motion = 0;
	data->x1 = -2.02;
	data->x2 = 0.6;
	data->y1 = -2.02;
	data->y2 = 1.2;
	data->zoom = 204;
	data->col = 0xef0b0b;
	data->x = 0;
	data->y = 0;
	return (data);
}
