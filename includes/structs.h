/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:19:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/05 09:41:59 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"

typedef struct	s_img
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_img;

typedef struct	s_menu_l
{
	t_img		*menu_ico;
	t_img		*one;
	t_img		*two;
	t_img		*three;
	t_img		*bordure_left;
	t_img		*button_grey;
	t_img		*bordure_top;
	t_img		*bordure_bottom;
}				t_menu_l;

typedef struct	s_data
{
	long double	zoom;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	int			color;
	int			x;
	int			y;
	int			iter;
	// int			mouse_pos;
	int			i;
}				t_data;

typedef struct	s_app
{
	t_img		*img;
	t_menu_l	*menu_l;
	t_img		*background;
	t_data		*data;
	void		*mlx_ptr;
	void		*mlx_win;
	int			mapname;
}				t_app;

#endif
