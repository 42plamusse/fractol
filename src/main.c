/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:25:35 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/31 17:11:18 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_mlx		env;
	t_numbers	num;

	if (argc != 2 && argc != 3)
		ft_perror(USAGE);
	env.num = &num;
	flags(&env, argc, argv);
	init_env(&env);
	mlx_hook(env.win, 4, 0, &position, &env);
	mlx_hook(env.win, 2, 0, &control, &env);
	mlx_hook(env.win, 6, 0, &motion, &env);
	mlx_loop(env.mlx);
	return (0);
}
