/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:03:44 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/31 15:17:30 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static void		init_mandel(t_mlx *env)
{
	env->mandel = 1;
	env->num->x1 = -2;
	env->num->y1 = -2;
	env->num->zoom = 200;
	env->num->i_max = 50;
	env->win_w = 800;
	env->win_h = 800;
}

static void		init_burning(t_mlx *env)
{
	env->burning= 1;
	env->num->x1 = -2;
	env->num->y1 = -2;
	env->num->zoom = 200;
	env->num->i_max = 50;
	env->win_w = 800;
	env->win_h = 800;
}

static void 	init_julia(t_mlx *env)
{
	env->julia = 1;
	env->num->x1 = -2;
	env->num->y1 = -2;
	env->num->zoom = 200;
	env->num->i_max = 50;
	env->num->cr = 0.285;
	env->num->ci = 0.01;
	env->win_w = 800;
	env->win_h = 800;
}

void			ft_perror(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void			flags(t_mlx *env, int argc, char **argv)
{
	char	*tmp;

	env->mandel = 0;
	env->burning = 0;
	env->julia = 0;
	tmp = argv[1];
	if (argc == 3)
	{
		if (ft_strcmp(tmp, JULIA) == 0)
			env->julia = 1;
		else
			ft_perror(USAGE);
		tmp = argv[2];
	}
	if (ft_strcmp(tmp, MANDELBROT) == 0)
		init_mandel(env);
	else if (ft_strcmp(tmp, BURNINGSHIP) == 0)
		init_burning(env);
	else
		ft_perror(USAGE);
	if (env->julia && (env->mandel || env->burning))
		init_julia(env);
}

void			init_env(t_mlx *env)
{
	t_img	ctx;

	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, env->win_w, env->win_h);
	env->data = (int*)mlx_get_data_addr(env->img, &ctx.bpp, &ctx.sl, &ctx.endian);
	build_fractal(env);
	env->win = mlx_new_window(env->mlx, env->win_w, env->win_h, "Fractale");
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
