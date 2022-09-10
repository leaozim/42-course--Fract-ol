/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:29:38 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/10 20:20:37 by lade-lim         ###   ########.fr       */
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
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double)n / 100;
	if (frac->set == JULIA)
	{
		r = sin(frac->color_ju * n + 20) * 125 + 126;
		g = sin(frac->color_ju * n + 53) * 125 + 126;
		b = sin(frac->color_ju * n + 10) * 125 + 126;
	}
	else
	{
		r = (int)(9 * (1 - t) * pow(t, 3) * frac->color1);
		g = (int)(15 * pow(1 - t, 2) * pow(t, 2) * frac->color2);
		b = (int)(8.5 * pow(1 - t, 3) * t * frac->color3);
	}
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
	else
	{
		if (n == frac->max_iterations)
			my_mlx_pixel_put(frac, 0x000000);
		else
			my_mlx_pixel_put(frac, set_color(frac, n));
	}
}

void	change_color(t_fractol *frac)
{
	frac->color_ju = 0.03;
	frac->color1 = 256;
	frac->color2 = 50;
	frac->color3 = 255;
	redraw_image(frac);
}