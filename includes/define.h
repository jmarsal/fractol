/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:01:29 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/09 11:29:18 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
** Win
*/

# define TITLE "fractol by jmarsal"
# define MLX_WIN app->mlx_win
# define MLX_PTR app->mlx_ptr
# define WIDTH 1920
# define HEIGHT 1080
# define WIDTH_DRAW 1300
# define HEIGHT_DRAW 800
# define SIZE_MENU_W 350
# define SIZE_MENU_H 100
# define MASK_CLOSE 1L << 17
# define SCROLL "- Scroll up or down for Zoom"
# define ARROWS "- Keys Arrows for move"
# define AUTEUR "Jean-Baptiste Marsal"
# define PARAMETERS "PRESS O FOR RESET PARAMETERS"

/*
** KEYCODE
*/

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 125
# define DOWN 126
# define ORIGIN 31
# define ZOOMUP 4
# define ZOOMDOWN 5

/*
** Colors
*/

# define GREEN 0xb6ff48
# define BLUE 0x1d4a64
# define BLUE_MENU 0x05199d
# define YELLOW 0xEAF74D
# define PINK 0xff00c1
# define RED 0xff0000
# define ORANGE 0xFFA500
# define MOUSE_ON BLUE
# define MOUSE_OFF RED
# define COLOR_START BLACK

/*
** Errors
*/

# define ERR3 "\033[31mError\033[0m : format = ./fractol [fractal]\n"
# define ERR1 ERR3 "\tType ./fractol [help] for more informations\n"
# define ERR2 "\033[31mError\033[0m : try with mandelbrot\n"
# define HELP3 "format = ./fractol [fractal]\n"
# define HELP2 HELP3 "You can try with : [mandelbrot] [julia] [bship] [tricorn]"
# define HELP HELP2 " [celtic] [chameleon] [sword] [my_fractal]\n"

#endif
