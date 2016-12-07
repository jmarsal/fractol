/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:19:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/07 16:44:02 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"

typedef struct	s_bool
{
	int			mandel;
	int			julia;
}				t_bool;

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
	t_img		*menu_fract;
	t_img		*menu_fract2;
	t_img		*menu_fract3;
}				t_menu_l;

typedef struct	s_menu_b
{
	t_img		*slider_motion;
	t_img		*slider_iter;
	t_img		*plus;
	t_img		*minus;
}				t_menu_b;

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
	int			iter_on;
	int			motion;
	int			i;
}				t_data;

typedef struct	s_app
{
	t_img		*img;
	t_menu_l	*menu_l;
	t_menu_b	*menu_b;
	t_img		*background;
	t_data		*data;
	t_bool		bool_button;
	void		*mlx_ptr;
	void		*mlx_win;
	int			mapname;
	int			burger;
}				t_app;

#endif
