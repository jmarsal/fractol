/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:54:07 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 09:50:43 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "define.h"
# include "structs.h"
# include "libft.h"

#include <stdio.h>

int			start_treatment(t_app	*app, int map, char *mapname);
void		put_img_menu_l_to_win(t_app *app, t_menu_l *tmp);
void		put_img_menu_b_to_win(t_app *app, t_menu_b *tmp);
int			refresh_win(t_app *app);
void		origin(int keycode, t_app *app);
int			close_win(t_app *app);

/*
** memory
*/

t_app		*init_app(int map, int *h, int *w, char *mapname);
t_menu_l	*init_left_menu(t_app *app, int *h, int *w);
t_menu_l	*fill_menu_left(t_app *app, t_menu_l *tmp, int *h, int *w);
t_menu_b	*fill_menu_bottom(t_app *app, t_menu_b *tmp, int *h, int *w);
t_menu_b	*init_bottom_menu(t_app *app, int *h, int *w);
void		init_mlx(t_app *app);
t_img		*init_img(t_app *app, int width, int height);
void		app_destroy(t_app *app);
t_data		*init_coords_mandelbrot(t_app *app);
t_data		*init_julia(t_app *app);
t_data		*init_win(t_app *app);
void		init_bool(t_bool *bool_button);
int			check_color_on(t_app *app, int color);
t_theme		*init_theme(void);

/*
** output
*/

void		mlx_put_pixel_to_image(t_app *app, int x, int y, int color);
void		put_pixel_and_choose_color(t_app *app);
void		draw_mandelbrot(t_app *app);
void		draw_julia(t_app *app);

/*
** events
*/

int			key_funct(int keycode, t_app *app);
int			mouse_funct(int button, int x, int y, t_app *app);
int			mouse_motion_menu(int x, int y, t_app *app);
void		move_tray(int keycode, t_app *app);
void		motion_button_activate(int x, int y, t_app *app);
void		motion_button_activate2(int x, int y, t_app *app);
void		motion_button_desactivate(t_app *app);
void		if_slider_iter_on(int x, int y, t_app *app);
void		if_slider_iter_off(int x, int y, t_app *app);
void		if_plus_iter(int x, int y, t_app *app);
void		if_minus_iter(int x, int y, t_app *app);
void		if_clic_button(int x, int y, t_app *app);
void		put_newpos_of_slider_theme(t_app *app);

#endif
