/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:25:35 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/18 19:00:41 by plamusse         ###   ########.fr       */
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

int		series(t_numbers *num)
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

void	mandelbrot(t_mlx *env, t_numbers *num)
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
			num->zr = 0;
			num->zi = 0;
			num->ci = y / num->zoom + num->y1;
			num->cr = x / num->zoom + num->x1;
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