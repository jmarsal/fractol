/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_divers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:33:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 11:50:06 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img			*init_img(t_app *app, int width, int height)
{
	t_img	*img;

	img = NULL;
	if (!(img = ft_memalloc(sizeof(t_img))))
		return (NULL);
	img->img_ptr = mlx_new_image(MLX_PTR, width, height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	return (img);
}

void			init_mlx(t_app *app)
{
	if (!(MLX_PTR = mlx_init()))
		exit(EXIT_FAILURE);
	if (!(MLX_WIN =
		mlx_new_window(MLX_PTR, WIDTH, HEIGHT, TITLE)))
	{
		ft_free(MLX_PTR);
		exit(EXIT_FAILURE);
	}
}

t_data			*init_win(t_app *app)
{
	t_data	*tmp;

	tmp = NULL;
	if (app->mapname == 1 || app->mapname == 3 ||
		app->mapname == 4 || app->mapname == 5)
		tmp = init_coords_mandelbrot(app);
	else
		tmp = init_julia(app);
	return (tmp);
}
