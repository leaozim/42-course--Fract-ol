/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:18:58 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/16 03:11:47 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_julia(t_fractol *data, char **argv)
{
	data->kmax = ft_atof(argv[2]);
	data->kmin = ft_atof(argv[3]);
}

void	init_structs(t_fractol *data, char **argv)
{
	data->y = 0;
	data->x = 0;
	data->n = 0;
	data->press = 0;
	data->color_ju = 0.08;
	data->color1 = 255;
	data->color2 = 50;
	data->color3 = 255;
	data->xmax = 2.5;
	data->xmin = -2.5;
	data->ymin = -2.5;
	data->ymax = data->ymin + (data->xmax - data->xmin) * WIDTH / HEIGHT;
	data->zmax = 0;
	data->zmin = 0;
	data->kmax = 0.355;
	data->kmin = 0.355;
	data->max_iterations = 100;
	if (data->set == JULIA)
		init_julia(data, argv);
}
