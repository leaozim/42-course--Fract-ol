/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <larissa_silva@outlook.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:50:17 by lade-lim          #+#    #+#             */
/*   Updated: 2023/05/03 15:39:20 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	draw_fractol(t_fractol *frac)
{
	int	n;

	frac->x = 0;
	frac->y = 0;
	n = 0;
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

void	redraw_image(t_fractol *f)
{
	mlx_clear_window(f->w_data.mlx, f->w_data.win);
	draw_fractol(f);
	mlx_put_image_to_window(f->w_data.mlx, f->w_data.win, f->w_data.img, 0, 0);
	menu(f);
}
