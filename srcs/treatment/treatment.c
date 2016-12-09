/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:10:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 11:52:27 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			close_win(t_app *app)
{
	app_destroy(app);
	exit(EXIT_SUCCESS);
}

static void	put_menu_and_str_to_win(t_app *app)
{
	put_img_menu_l_to_win(app, app->menu_l);
	put_img_menu_b_to_win(app, app->menu_b);
	mlx_string_put(MLX_PTR, MLX_WIN, 930, 50, 0x7E7E93, app->fractal);
	mlx_string_put(MLX_PTR, MLX_WIN, 1760, 338, ORANGE,
		ft_itoa_base((long)app->data->iter, 10));
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->img->img_ptr, SIZE_MENU_W, SIZE_MENU_H);
}

int			refresh_win(t_app *app)
{
	int		h;
	int		w;

	h = HEIGHT;
	w = WIDTH;
	mlx_clear_window(MLX_PTR, MLX_WIN);
	app->background->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/background.xpm", &w, &h);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->background->img_ptr, 0, 0);
	if (app->mapname == 1 || app->mapname == 3 ||
		app->mapname == 4 || app->mapname == 5)
		draw_mandelbrot(app);
	else
		draw_julia(app);
	put_menu_and_str_to_win(app);
	return (0);
}

/*
** Init app, lance les calculs en fonction de la mapname et print
*/

int			start_treatment(t_app *app, int map, char *mapname)
{
	int		h;
	int		w;

	h = HEIGHT;
	w = WIDTH;
	if (!(app = init_app(map, &h, &w, mapname)))
		return (-1);
	if (app->mapname == 1 || app->mapname == 3 ||
		app->mapname == 4 || app->mapname == 5)
		draw_mandelbrot(app);
	else
		draw_julia(app);
	app->background->img_ptr = mlx_xpm_file_to_image(MLX_PTR,
		"srcs/img/background.xpm", &w, &h);
	mlx_put_image_to_window(MLX_PTR, MLX_WIN,
		app->background->img_ptr, 0, 0);
	put_menu_and_str_to_win(app);
	mlx_hook(MLX_WIN, 2, 3, key_funct, app);
	mlx_hook(MLX_WIN, 6, 1 << 8, mouse_motion_menu, app);
	mlx_mouse_hook(MLX_WIN, mouse_funct, app);
	mlx_hook(MLX_WIN, 17, MASK_CLOSE, close_win, app);
	mlx_loop(MLX_PTR);
	return (0);
}
