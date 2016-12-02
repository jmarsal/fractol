/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:54:07 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/02 17:03:40 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_win(t_mlx *mlx)
{
	ft_free(mlx);
	exit(0);
}

static void		mlx_put_pixel_to_image(t_app *app, int x, int y, int color)
{
	int octet;

	octet = app->img->bpp / 8;
	if (x > 0 && x < app->WIDTH_DRAW && y > 0 && y < HEIGHT_DRAW)
		ft_memcpy(&app->img->data[octet * (x + app->img->sizeline /
										octet * (y)], &color, octet);
}

void		set_pixel_to_image(t_app *e)
{
	if (e->data->i == e->data->iter)
		mlx_put_pixel_to_image(e, e->data->x, e->data->y, 0);
	else
		mlx_put_pixel_to_image(e, e->data->x, e->data->y, e->data->col * e->data->i / e->data->iter);
}

void		draw_windows(t_app *e)
{
	while (e->data->x < X_SIZE)
	{
		e->data->y = 0;
		while (e->data->y < Y_SIZE)
		{
			e->data->c_r = e->data->x / e->data->zoom + e->data->x1;
			e->data->c_i = e->data->y / e->data->zoom + e->data->y1;
			e->data->z_r = 0;
			e->data->z_i = 0;
			e->data->i = 0;
			while ((e->data->z_r * e->data->z_r + e->data->z_i * e->data->z_i) < 4 &&
					e->data->i < e->data->iter)
			{
				e->data->tmp = e->data->z_r;
				e->data->z_r = e->data->z_r * e->data->z_r - e->data->z_i *
					e->data->z_i + e->data->c_r;
				e->data->z_i = 2 * e->data->z_i * e->data->tmp + e->data->c_i;
				e->data->i++;
			}
			set_pixel_to_image(e);
			e->data->y++;
		}
		e->data->x++;
	}
	e->data->x = 0;
}

/*
** Init app, lance les calculs en fonction de la mapname et print
*/

int	start_treatment(t_app *app, const char *mapname)
{
	int		h;
	int		w;

	h = HEIGHT_DRAW;
	w = WIDTH_DRAW;

	/* Init de l'app en fonction de la map */
	if (!(app = init_app(mapname)))
		return (-1);

	/* Replissage de la data en fonction de la fractale */
	draw_windows(app);

	/* Replissage de l'image en fonction de la fractale */
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->img->img_ptr, SIZE_MENU_W, SIZE_MENU_H);

	/* Interaction utilisateur */
	mlx_hook(MLX_WIN, 17, MASK_CLOSE, close_win, &app->mlx);

	/* Loop tant que */
	mlx_loop(MLX_PTR);

	return (0);
}
