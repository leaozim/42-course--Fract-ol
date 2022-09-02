// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   julia.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/08/26 21:44:18 by lade-lim          #+#    #+#             */
// /*   Updated: 2022/08/29 22:25:21 by lade-lim         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../fractol.h"

int	to_draw_julia(t_fractol *frac)
{
	int		n;
	double temp;
	double	va_z;
	
	n = 0;
	va_z = 0;
	frac->z_re = frac->c_re;
	frac->z_im = frac->c_im;
	while(n < frac->max_iterations && va_z < 4)
	{
		temp = pow(frac->z_re, 2) - pow(frac->z_im, 2) + frac->k_re;
		frac->z_im  = (2 * frac->z_re * frac->z_im) + frac->k_im;
		frac->z_re = temp;
		va_z = pow(frac->z_re, 2) + pow(frac->z_im, 2);
		n++;
	}
	return (n);
}

int julia(t_fractol *frac)
{
	double	n;

	while (frac->x < FRAC_WW)
	{
		while(frac->y < FRAC_WH)
		{
			frac->c_re = frac->x_im + frac->x * (frac->x_re - frac->x_im)/FRAC_WW;
			frac->c_im = frac->y_im + frac->y * (frac->y_re - frac->y_im)/FRAC_WH;
			n = to_draw_julia(frac);
			if(n == frac->max_iterations)
				my_mlx_pixel_put(frac,  0x4B0082);
			else
				my_mlx_pixel_put(frac,  set_color(n));
			frac->y++;
		}
		frac->x++;
		frac->y = 0;
	}
	return(0);
}
