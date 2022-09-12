/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:32:20 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/12 20:18:55 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyboard_events(int key, t_fractol *f)
{
	if (key == ESC)
		close_window(f);
	else if (key == ONE || key == TWO)
		set_new_frac(key, f);
	else if (key == R)
		reset_frac(f);
	redraw_image(f);
	return (0);
}

void	set_new_frac(int key, t_fractol *f)
{
	if (key == ONE && f->set != MANDELBROT)
		f->set = MANDELBROT;
	else if (key == TWO && f->set != JULIA)
		f->set = JULIA;
}

void	reset_frac(t_fractol *frac)
{
	frac->xmax = 2.5;
	frac->xmin = -2.5;
	frac->ymin = -2.5;
	frac->ymax = frac->ymin + (frac->xmax - frac->xmin) * WIDTH / HEIGHT;
}
