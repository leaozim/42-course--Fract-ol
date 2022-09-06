/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:29:38 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/06 20:22:55 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_fractol *frac, int n)
{
	unsigned int	*dst;

	dst = frac->w_data.addr + (frac->y * frac->w_data.line_length + \
	frac->x * (frac->w_data.bit_per_pixel / 8));
	*(unsigned int *)dst = n;
}

int	set_color(t_fractol *frac, int n)
{
	int	r;
	int	g;
	int	b;
	double t;

	t = (double)n / 100;
	if (frac->set == JULIA)
	{
		r = sin(0.08 * n + 10 + 10) * 128 + 127;
		g = sin(0.08 * n + 1 + 52) * 128 + 127;
		b = sin(0.08 * n + 10 + 0) * 128 + 127;
	}
	if (frac->set ==  MANDELBROT)
	{
		r = (int)(9 * (1 - t) * pow(t, 3) * 255);
		g = (int)(15 * pow(1 - t, 2) * pow(t, 2) * 50);
		b = (int)(8.5 * pow(1 - t, 3) * t * 100);
	}
	// r = 250 * t * 1;
	// g = 100* t;
	// b =	256 * t * 10;
	return (r << 16 | g << 8 | b);
}

void	set_color_frac(t_fractol *frac, int n)
{
	if (frac->set == JULIA)
	{
		if (n == frac->max_iterations)
			my_mlx_pixel_put(frac, 0x4B0082);
		else
			my_mlx_pixel_put(frac, set_color(frac, n));
	}
	if (frac->set == MANDELBROT)
	{
		if (n == frac->max_iterations)
			my_mlx_pixel_put(frac, 0x000000);
		else
			my_mlx_pixel_put(frac, set_color(frac, n));
	}
}
