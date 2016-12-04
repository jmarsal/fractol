/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:01:29 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/04 01:10:08 by jmarsal          ###   ########.fr       */
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

/*
** Colors
*/

# define BLACK 0x000000
# define BLUE 0x1d4a64
# define PINK 0xff00c1
# define COLOR_START BLACK

/*
** Errors
*/

# define ERR1 "\033[31mError\033[0m : format = ./fractol map\n"
# define ERR2 "\033[31mError\033[0m : try with mandelbrot\n"

#endif
