/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:54:07 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/05 12:47:06 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "define.h"
# include "structs.h"
# include "libft.h"

int			start_treatment(t_app	*app, const char *mapname);
void		put_img_menu_l_to_win(t_app *app, t_menu_l *tmp);
int			refresh_win(t_app *app);
void		origin(int keycode, t_app *app);

/*
** memory
*/

t_app		*init_app(const char *mapname, int *h, int *w);
t_menu_l	*init_left_menu(t_app *app, int *h, int *w);
void		init_mlx(t_app *app);
t_img		*init_img(t_app *app, int width, int height);
void		app_destroy(t_app *app);
t_data		*init_coords_mandelbrot(void);
t_data		*init_win(t_app *app);

/*
** output
*/

void		mlx_put_pixel_to_image(t_app *app, int x, int y, int color);
void		put_pixel_and_choose_color(t_app *app);
void		draw_mandelbrot(t_app *app);

/*
** events
*/

int			key_funct(int keycode, t_app *app);
int			mouse_funct(int button, int x, int y, t_app *app);
int			mouse_motion_menu(int x, int y, t_app *app);
void		move_tray(int keycode, t_app *app);

#endif
