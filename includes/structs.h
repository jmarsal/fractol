/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:19:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/25 16:08:36 by jmarsal          ###   ########.fr       */
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
	int				x;
	int				y;
	float			z;
	int				color;
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
	// t_win			*win;
	t_img			*img;
}					t_print;

typedef struct		s_fract
{
	t_print			*win;
	char			*map_name;
}					t_fract;

#endif
