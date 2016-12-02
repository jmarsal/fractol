/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:19:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/01 18:11:31 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// typedef struct		s_win
// {
// 	t_size_win		*size;
// 	double			move_z;
// 	float			zoom;
// 	float			zoom_change;
// 	int				move_horizontal;
// 	int				move_vertical;
// 	int				witch_proj;
// 	char			*filename;
// }					t_win;

typedef struct		s_coords
{
	double			x;
	double			x1;
	double			y;
	double			y2;
	double			c;
	double			ci;
	double			z;
	double			zi;
	int				color;
	unsigned int	zoom;
	unsigned int	iter_max;
}					t_coords;

typedef struct		s_img
{
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
}					t_mlx;

typedef struct		s_print
{
	t_mlx			*mlx;
	t_img			*img;
	t_coords		**coords;
}					t_print;

typedef struct		s_app
{
	t_print			*win;
	char			*map_name;
}					t_app;

#endif
