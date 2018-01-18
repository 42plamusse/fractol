/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:31:58 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/11 18:45:55 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78
# define KEY_ITER_MORE 116
# define KEY_ITER_LESS 121

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
	t_numbers	*num;
}				t_mlx;

void	zoom_in(t_mlx *env);
int		zoom(int keycode, t_mlx *env);
int		control(int keycode, t_mlx *env);
void	build_fractal(t_mlx *env, t_numbers *num, int (*fractal)(t_numbers*));
int		mandelbrot(t_numbers *num);
int		position(int button, int x, int y, t_mlx *env);

#endif
