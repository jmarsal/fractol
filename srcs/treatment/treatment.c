/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:54:07 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/04 01:07:01 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_win(t_app *app)
{
	ft_free(MLX_PTR);
	exit(0);
}

void		mlx_put_pixel_to_image(t_app *app, int x, int y, int color)
{
	int octet;

	octet = app->img->bpp / 8;
	if (x > 0 && x < WIDTH_DRAW && y > 0 && y < HEIGHT_DRAW)
		ft_memcpy(&app->img->data[octet * (x + app->img->sizeline /
										octet * y)], &color, octet);
}

void		put_pixel_and_choose_color(t_app *app)
{
	if (app->data->i == app->data->iter)
		mlx_put_pixel_to_image(app, app->data->x, app->data->y, COLOR_START);
	else
		mlx_put_pixel_to_image(app, app->data->x, app->data->y,
			app->data->color * app->data->i / app->data->iter);
}

/*
** Init app, lance les calculs en fonction de la mapname et print
*/

int	start_treatment(t_app *app, const char *mapname)
{
	int		h;
	int		w;

	h = HEIGHT;
	w = WIDTH;

	/* Init de l'app en fonction de la map */
	if (!(app = init_app(mapname)))
		return (-1);

	/* Replissage de la data en fonction de la fractale */
	if (app->mapname == 1)
		draw_mandelbrot(app);
	
	/* Background */
	app->background->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/background.xpm", &w, &h);
	app->img_ico->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/menu.xpm", &w, &h);
	app->bordure_left->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/borders.xpm", &w, &h);
	app->one->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/one.xpm", &w, &h);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->background->img_ptr, 0, 0);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->img_ico->img_ptr, 30, 30);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->bordure_left->img_ptr, 342, 93);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->one->img_ptr, 35, 130);
	mlx_string_put(MLX_PTR, MLX_WIN, 110, 50, 0x7E7E93, "CHOOSE FRACTALS");
	mlx_string_put(MLX_PTR, MLX_WIN, 110, 135, 0x7E7E93, "MANDELBROT");

	if (app->mapname == 1)
		mlx_string_put(MLX_PTR, MLX_WIN, 930, 50, 0x7E7E93, "MANDELBROT");

	/* Replissage de l'image en fonction de la fractale */
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->img->img_ptr, SIZE_MENU_W, SIZE_MENU_H);

	/* Interaction utilisateur */
	mlx_hook(MLX_WIN, 17, MASK_CLOSE, close_win, app);

	/* Loop tant que */
	mlx_loop(MLX_PTR);

	return (0);
}
