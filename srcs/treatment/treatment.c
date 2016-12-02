/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:54:07 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/02 09:35:27 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_win(t_mlx *mlx)
{
	ft_free(mlx);
	exit(0);
}

/*void		draw_windows(t_app *app)
{
	t_coords	**n_data;
	size_t		lines;
	size_t		elems;

	n_data = app->data->data_elem;
	lines = 0;
	elems = 0;
	while (n_data[lines])
	{
		elems = 0;
		while (elems < app->params->x_max)
		{
			draw_line(app, n_data, lines, elems);
			draw_columns(app, n_data, lines, elems);
			elems++;
		}
		lines++;
	}
}*/

/*
** Init app, lance les calculs en fonction de la mapname et print
*/

int	start_treatment(t_app *app, const char *mapname)
{
	int		h;
	int		w;

	h = HEIGHT_DRAW;
	w = WIDTH_DRAW;
	if (!(app = init_env(mapname)))
		return (-1);
	// app->win->mlx = init_mlx();
	ft_putstr(mapname);
	// draw_windows(app);
	// mlx_put_image_to_window(MLX_PTR, MLX_WIN,
	// 	app->win->img->img_ptr, SIZE_MENU_W, SIZE_MENU_H);
	mlx_hook(MLX_WIN, 17, MASK_CLOSE, close_win, &app->win->mlx);
	mlx_loop(MLX_PTR);
	return (0);
}
