/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:18:17 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/19 18:28:34 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	series(t_numbers *num)
{
	int		i;

	i = 0;
	while ((num->zr * num->zr + num->zi * num->zi) < 4 && i < num->i_max)
	{
		num->tmp = num->zr;
		num->zr = num->zr * num->zr - num->zi * num->zi + num->cr;
		num->zi = 2 * num->zi * num->tmp + num->ci;
		i++;
	}
	return (i);
}

void		julia(t_mlx *env, t_numbers *num)
{
	double		x;
	double		y;
	int			i;

	x = 0;
	while (x < env->win_w)
	{
		y = 0;
		while (y < env->win_h)
		{
			num->zi = y / num->zoom + num->y1;
			num->zr = x / num->zoom + num->x1;
			i = series(num);
			if (i != num->i_max)
				plot_pixel((int)x, (int)y, env, rgb(0, i * 255 / num->i_max , 0));
			else
				plot_pixel((int)x, (int)y, env, 0xFFFFF); 
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
