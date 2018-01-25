/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:03:44 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/25 17:17:22 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static void		init_mandel(t_mlx *env)
{
	env->num->x1 = -2.1;
	env->num->y1 = -1.2;
	env->num->zoom = 300;
	env->num->i_max = 50;
	env->win_w = 810;
	env->win_h = 720;
}

static void 	init_julia(t_mlx *env)
{
	env->num->x1 = -2;
	env->num->y1 = -2;
	env->num->zoom = 200;
	env->num->i_max = 50;
	env->num->cr = 0.285;
	env->num->ci = 0.01;
	env->win_w = 800;
	env->win_h = 800;
}

void			init_fractal(t_mlx *env)
{
	if (strcmp(env->name, MANDELBROT) == 0)
		init_mandel(env);
	else if (strcmp(env->name, JULIA) == 0)
		init_julia(env);
	else
	{
		printf(USAGE);
		exit(1);
	}
}

void			init_env(t_mlx *env, t_numbers *num, char *name)
{
	t_img	ctx;

	env->mlx = mlx_init();
	env->num = num;
	env->name = name;
	init_fractal(env);
	env->img = mlx_new_image(env->mlx, env->win_w, env->win_h);
	env->data = (int*)mlx_get_data_addr(env->img, &ctx.bpp, &ctx.sl, &ctx.endian);
	build_fractal(env);
	env->win = mlx_new_window(env->mlx, env->win_w, env->win_h, "Fractale");
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
