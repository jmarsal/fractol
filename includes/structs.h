/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:19:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/02 17:05:06 by jmarsal          ###   ########.fr       */
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
	int			col;
	int			x;
	int			y;
	int			iter;
	int			motion;
	int			i;
}				t_data;

typedef struct	s_app
{
	t_img		*img;
	t_data		*data;
	void		*mlx;
	void		*mlx_win;
	int			*mapname;
}				t_app;

#endif
