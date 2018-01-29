/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:14:39 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/19 17:15:59 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		plot_pixel(int x, int y, t_mlx *env, int color)
{
	int	*data_addr;

	data_addr = env->data;
	if (x >= 0 && y >= 0 && x < env->win_w && y < env->win_h)
		*(data_addr + (env->win_w * y) + x) = color;
}

int		rgb(int r, int g, int b)
{
	return (256 * 256 * r + 256 * g + b);
}
