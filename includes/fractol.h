/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:54:07 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/02 18:30:30 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "define.h"
# include "structs.h"
# include "libft.h"

int			start_treatment(t_app	*app, const char *mapname);

/*
** memory
*/

t_app		*init_app(const char *mapname);
void		init_mlx(t_app *app);
t_img		*init_img(t_app *app, int width, int height);
void		env_destroy(t_app *app);
t_data		*init_coords_mandelbrot(void);

/*
** output
*/

void		mlx_put_pixel_to_image(t_app *app, int x, int y, int color);
void		put_pixel_and_choose_color(t_app *app);
void		draw_mandelbrot(t_app *app);

#endif
