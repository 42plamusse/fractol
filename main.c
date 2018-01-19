/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:25:35 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/19 17:17:57 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_num(t_numbers *num)
{
	num->x1 = -2.1;
	//num->x2 = 0.6;
	num->y1 = -1.2;
	//num->y2 = 1.2;
	num->zoom = 300;
	//num->image_x = (num->x2 - num->x1) * num->zoom;
	//num->image_y = (num->y2 - num->y1) * num->zoom;
	num->i_max = 50;
	num->x = 0;
	num->y = 0;
}

void	build_fractal(t_mlx *env, t_numbers *num)
{
	if (strcmp(env->name, "mandelbrot") == 0)
		mandelbrot(env, num);
	else
	{
		printf("usage: ./fractol [fractale] (mandelbrot, julia, ...)\n");
		exit(1);
	}
}

int		main(int argc, char **argv)
{
	t_mlx	env;
	t_img	ctx;
	t_numbers	num;

	if (argc != 2)
	{
		printf("usage: %s [fractale] (mandelbrot, julia, ...)\n", argv[1]);
		return (-1);
	}
	env.win_w = 810;
	env.win_h = 720;
	env.mlx = mlx_init();
	env.img = mlx_new_image(env.mlx, env.win_w, env.win_h);
	env.data = (int*)mlx_get_data_addr(env.img, &ctx.bpp, &ctx.sl, &ctx.endian);
	env.num = &num;
	env.name = argv[1];
	init_num(&num);
	env.win = mlx_new_window(env.mlx, env.win_w, env.win_h, "Fractale");
	build_fractal(&env, &num);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_mouse_hook(env.win, &position, &env);
	mlx_hook(env.win, 2, 0, &control, &env);
	mlx_loop(env.mlx);
	return (0);
}
