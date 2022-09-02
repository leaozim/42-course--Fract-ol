// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mandelbrot.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/08/26 21:27:15 by lade-lim          #+#    #+#             */
// /*   Updated: 2022/08/26 21:31:23 by lade-lim         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../fractol.h"

int	to_draw_mandelbrot(t_fractol *frac)
{
	double temp;
	int n = 0;
	double aux = 0;

	frac->z_real = frac->c_real;
	frac->z_imag = frac->c_imag;
	while(n < frac->max_iterations && aux < 4)
	{
		temp = pow(frac->z_real, 2) - pow(frac->z_imag, 2) + frac->c_real;
		frac->z_imag  = (2 * frac->z_real * frac->z_imag) + frac->c_imag;
		frac->z_real = temp;
		aux = pow(frac->z_real, 2) + pow(frac->z_imag, 2);
		n++;
	}
	return (n);
}

#include <stdio.h>
int mandelbrot(t_fractol *frac)
{
	int n;

	frac->x = 0;
	frac->y = 0;
	while (frac->x < FRAC_WW)
	{
		while(frac->y < FRAC_WH)
		{
			frac->c_real = frac->x_imag + frac->x * (frac->x_real - frac->x_imag)/FRAC_WW;
			frac->c_imag = frac->y_imag + frac->y * (frac->y_real - frac->y_imag)/FRAC_WH;
			n = to_draw_mandelbrot(frac);
			if(n == frac->max_iterations)
				my_mlx_pixel_put(frac,  0x00000000);
			else
				my_mlx_pixel_put(frac,  set_color(n));
			frac->y++;
		}
		frac->x++;
		frac->y = 0;
	}

	return(0);
}
