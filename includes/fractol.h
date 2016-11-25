/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:57:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/25 16:52:23 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "define.h"
# include "structs.h"
# include "libft.h"

int		start_treatment(t_fract	*env, const char *mapname);

/*
** memory
*/

t_fract	*init_env(const char *mapname);
t_mlx	*init_mlx(void);

#endif
