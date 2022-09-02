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
	double va_z = 0;

	frac->z_re = frac->c_re;
	frac->z_im = frac->c_im;
	while(n < frac->max_iterations && va_z < 4)
	{
		temp = pow(frac->z_re, 2) - pow(frac->z_im, 2) + frac->c_re;
		frac->z_im  = (2 * frac->z_re * frac->z_im) + frac->c_im;
		frac->z_re = temp;
		va_z = pow(frac->z_re, 2) + pow(frac->z_im, 2);
		n++;
	}
	return (n);
}

int mandelbrot(t_fractol *frac)
{
	int n;

	frac->x = 0;
	frac->y = 0;
	while (frac->x < FRAC_WW)
	{
		while(frac->y < FRAC_WH)
		{
			frac->c_re = frac->x_im + frac->x * (frac->x_re - frac->x_im)/FRAC_WW;
			frac->c_im = frac->y_im + frac->y * (frac->y_re - frac->y_im)/FRAC_WH;
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
	return (0);
}
