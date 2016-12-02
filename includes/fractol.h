/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:57:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/12/02 09:16:03 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "define.h"
# include "structs.h"
# include "libft.h"

int		start_treatment(t_app	*app, const char *mapname);

/*
** memory
*/

t_app	*init_env(const char *mapname);
t_mlx	*init_mlx(void);
t_img	*init_img(t_app *app, int width, int height);
void	env_destroy(t_app *app);

#endif
