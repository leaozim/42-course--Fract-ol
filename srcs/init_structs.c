/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:18:58 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/02 21:36:36 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"

void	init_structs(t_fractol *data)
{
	data->y = 0;
	data->x = 0;
	data->x_re = 2.0;
	data->x_im = -2.0;
	data->y_im = -2.0;
	data->y_re = data->y_im + (data->x_re - data->x_im) * FRAC_WW/FRAC_WH;
	data->z_re = 0;
	data->z_im = 0;
	data->k_re =  -1.34882125854492;
	data->k_im = -0.454237874348958;
	data->max_iterations = 100;
}
