/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:18:58 by lade-lim          #+#    #+#             */
/*   Updated: 2022/08/30 22:50:23 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"

void	start_mandelbrot(t_fractol *data)
{
	data->y = 0;
	data->x = 0;
	data->x_real = 2;
	data->x_imag = -2;
	data->y_imag = -2;
	data->y_real = data->y_imag + (data->x_real - data->x_imag) * FRAC_WW/FRAC_WH;
	data->z_real = 0;
	data->z_imag = 0;
	data->c_const_real =  -1.34882125854492;
	data->c_const_img = -0.454237874348958;
	data->max_iterations = 100;
}
//  0.355534 - 0.337292i
// 0.4 + -0.59