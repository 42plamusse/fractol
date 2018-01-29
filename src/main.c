/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:25:35 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/29 11:39:49 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_mlx	env;
	t_numbers	num;

	if (argc != 2)
	{
		ft_printf(USAGE);
		return (-1);
	}
	init_env(&env, &num, argv[1]);
	ft_printf("%f\n", num.zoom);
	mlx_hook(env.win, 4, 0, &position, &env);
	mlx_hook(env.win, 2, 0, &control, &env);
	mlx_hook(env.win, 6, 0, &motion, &env);
	mlx_loop(env.mlx);
	return (0);
}
