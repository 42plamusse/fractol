/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:32:24 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/31 17:10:40 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	series(t_mlx *env, int x, int y)
{
	double		i;
	t_numbers	*num;

	num = env->num;
	i = 0;
	while ((num->zr * num->zr + num->zi * num->zi) < 4 && i < num->i_max)
	{
		num->tmp = num->zr;
		num->zr = num->zr * num->zr - num->zi * num->zi + num->cr;
		if (env->mandel)
			num->zi = 2 * num->zi * num->tmp + num->ci;
		else
			num->zi = 2 * ft_fabs(num->zi * num->tmp) + num->ci;
		i++;
	}
	if (i != num->i_max)
		plot_pixel(x, y, env, (rgb(255, 30, 100) * i / num->i_max));
	else
		plot_pixel(x, y, env, 0);
}

static void	set_complex_numbers(t_mlx *env, int x, int y)
{
	t_numbers	*num;

	num = env->num;
	if (env->julia)
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
}

void		build_fractal(t_mlx *env)
{
	double		x;
	double		y;

	x = 0;
	while (x < env->win_w)
	{
		y = 0;
		while (y < env->win_h)
		{
			set_complex_numbers(env, x, y);
			series(env, (int)x, (int)y);
			y++;
		}
		x++;
	}
}
