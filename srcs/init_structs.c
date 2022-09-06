/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:18:58 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/06 20:35:25 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_julia(t_fractol *frac, int argc, char **argv)
{
	frac->kmax = ft_atof(argv[2]);
	frac->kmin = ft_atof(argv[3]);
}

void	init_structs(t_fractol *data, int argc, char **argv)
{
	data->y = 0;
	data->x = 0;
	data->xmax = 2.0;
	data->xmin = -2.0;
	data->ymin = -2.0;
	data->ymax = data->ymin + (data->xmax - data->xmin) * WIDTH / HEIGHT;
	data->zmax = 0;
	data->zmin = 0;
	data->kmax = 0.355;
	data->kmin = 0.355;
	data->max_iterations = 100;
	if (data->set == JULIA && argc > 2)
		init_julia(data, argc, argv);
}
