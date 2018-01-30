/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:31:58 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/30 14:55:06 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include "/Users/plamusse/fractol/libft/includes/libft.h"

# define USAGE "usage: ./fractol [--julia] fractal (mandelbrot | burningship)"
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78
# define KEY_ITER_MORE 116
# define KEY_ITER_LESS 121
# define KEY_JULIA 38
# define KEY_EXIT 53
# define MANDELBROT "mandelbrot"
# define BURNINGSHIP "burningship"
# define JULIA "--julia"

typedef struct	s_img
{
	int		bpp;
	int		sl;
	int		endian;
}				t_img;

typedef struct	s_numbers
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom;
	int			image_x;
	int			image_y;
	double		zi;
	double		ci;
	double		zr;
	double		cr;
	int			i;
	int			i_max;
	double		x;
	double		y;
	double		tmp;
}				t_numbers;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*data;
	int		win_w;
	int		win_h;
	char	*name;
	int		julia;
	int		mandel;
	int		burning;
	t_numbers	*num;
}				t_mlx;

int		zoom(int keycode, t_mlx *env);
int		control(int keycode, t_mlx *env);
void	build_fractal(t_mlx *env);
void	mandelbrot(t_mlx *env, t_numbers *num);
void	julia(t_mlx *env, t_numbers *num);
int		position(int button, int x, int y, t_mlx *env);
int		motion(int x, int y, t_mlx *env);
int		rgb(int r, int g, int b);
void	plot_pixel(int x, int y, t_mlx *env, int color);
void	init_env(t_mlx *env);
void	flags(t_mlx *env, int argc, char **argv);
void	ft_perror(char *str);

#endif
