/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:50:17 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/11 16:57:16 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	draw_fractol(t_fractol *frac)
{
	int	n;

	frac->x = 0;
	frac->y = 0;
	while (frac->x < WIDTH)
	{
		while (frac->y < HEIGHT)
		{
			frac->cent_x = frac->xmax - frac->xmin;
			frac->cent_y = frac->ymax - frac->ymin;
			frac->cmax = frac->xmin + frac->x * frac->cent_x / WIDTH;
			frac->cmin = frac->ymin + frac->y * frac->cent_y / HEIGHT;
			if (frac->set == MANDELBROT)
				n = mandelbrot(frac);
			if (frac->set == JULIA)
				n = julia(frac);
			if (frac->set == CELTIC)
				n = celtic(frac);
			set_frac_color(frac, n);
			frac->y++;
		}
		frac->x++;
		frac->y = 0;
	}
	return (0);
}
