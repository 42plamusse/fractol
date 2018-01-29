/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:32:24 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/29 18:44:18 by plamusse         ###   ########.fr       */
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
		num->zi = 2 * ft_fabs(num->zi * num->tmp) + num->ci;
		i++;
	}
	return (i);
}

void	build_fractal(t_mlx *env)
{
	double		x;
	double		y;
	int			i;
	t_numbers	*num;

	num = env->num;
	x = 0;
	while (x < env->win_w)
	{
		y = 0;
		while (y < env->win_h)
		{
			if (strcmp(env->name, JULIA) == 0)
			{
				num->zi = y / num->zoom + num->y1;
				num->zr = x / num->zoom + num->x1;
			}
			else
			{
				num->zr = 0;
				num->zi = 0;
				num->ci = y / num->zoom + num->y1;
				num->cr = x / num->zoom + num->x1;
			}
			i = series(num);
			if (i != num->i_max)
				plot_pixel((int)x, (int)y, env, rgb(0, i * 255 / num->i_max , 0));
			else
				plot_pixel((int)x, (int)y, env, 0xFFFFF); 
			y++;
		}
		x++;
	}
}
