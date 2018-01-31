/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:27:16 by plamusse          #+#    #+#             */
/*   Updated: 2018/01/31 12:47:11 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(double i, double i_max)
{
	int		color;

	color = 0;
	if (i < (i_max / 32))
		color = rgb(30, 150, 255);
	else if (i < (i_max / 16))
		color = rgb(50, 180, 100);
	else if (i < (i_max / 8))
		color = rgb(255, 150, 0);
	else if (i < (i_max / 4))
		color = rgb(93, 134, 255);
	else if (i < (i_max / 2))
		color = rgb(255, 242, 75);
	else if (i < ((i_max / 2) + (i_max / 8)))
		color = rgb(255, 30, 100);
	else if (i < ((i_max / 2) + (i_max / 4)))
		color = rgb(100, 255, 50);
	else if (i < ((i_max / 2) + (i_max / 4) + (i_max / 8)))
		color = rgb(200, 100, 200);
	else
		color = rgb(255, 255, 255);
	return (color);
}
