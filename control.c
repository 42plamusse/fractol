/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:01:16 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/11 18:45:29 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_in(t_mlx *env)
{
	env->num->x1 = env->num->x1 + (env->win_w / (2 * env->num->zoom)) * (1 - 1 / 1.2);
	env->num->y1 = env->num->y1 + (env->win_h / (2 * env->num->zoom)) * (1 - 1 / 1.2);
	env->num->zoom *= 1.2;
}

static void	zoom_out(t_mlx *env)
{
	env->num->x1 = env->num->x1 + (env->win_w / (2 * env->num->zoom)) * (1 - 1 / 0.8);
	env->num->y1 = env->num->y1 + (env->win_h / (2 * env->num->zoom)) * (1 - 1 / 0.8);
	env->num->zoom *= 0.8;
}

int		position(int button, int x, int y, t_mlx *env)
{
	if (button == 1 && x > 0 && y > 0)
	{
		env->num->x1 = ((double)x / env->num->zoom) + env->num->x1 - (env->win_w / (2 * env->num->zoom));
		env->num->y1 = ((double)y / env->num->zoom) + env->num->y1 - (env->win_h / (2 * env->num->zoom));
		build_fractal(env, env->num, &mandelbrot);
		printf("%d, %d\n", x, y);
		printf("%f, %f\n", env->num->x1, env->num->y1);
	}
	return (0);
}

int		control(int keycode, t_mlx *env)
{
	bzero((void*)env->data, (env->win_w * env->win_h * 4));
	if (keycode == KEY_ZOOM_IN)
		zoom_in(env);
	if (keycode == KEY_ZOOM_OUT)
		zoom_out(env);
	if (keycode == KEY_LEFT)
		env->num->x1 -= env->win_w / env->num->zoom / 12;
	if (keycode == KEY_RIGHT)
		env->num->x1 += env->win_w / env->num->zoom / 12;
	if (keycode == KEY_DOWN)
		env->num->y1 += env->win_h / env->num->zoom / 12;
	if (keycode == KEY_UP)
		env->num->y1 -= env->win_h / env->num->zoom / 12;
	if (keycode == KEY_ITER_MORE)
		env->num->i_max += 5;
	if (keycode == KEY_ITER_LESS)
		env->num->i_max -= 5;
	build_fractal(env, env->num, &mandelbrot);
	return (keycode);
}
