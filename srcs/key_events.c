/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:32:20 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/16 03:11:57 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyboard_events(int key, t_fractol *f)
{
	if (key == ESC)
		close_window(f);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		fractol_move(key, f);
	else if (key == ONE || key == TWO || key == THREE)
		set_new_frac(key, f);
	else if (key == R)
		reset_frac(f);
	else if (key == C)
		change_color(f);
	redraw_image(f);
	return (0);
}

void	fractol_move(int key, t_fractol *frac)
{
	if (key == LEFT)
	{
		frac->xmin -= frac->cent_x / 100;
		frac->xmax -= frac->cent_x / 100;
	}
	else if (key == RIGHT)
	{
		frac->xmin += frac->cent_x / 100;
		frac->xmax += frac->cent_x / 100;
	}
	else if (key == UP)
	{
		frac->ymax -= frac->cent_y / 100;
		frac->ymin -= frac->cent_y / 100;
	}
	else if (key == DOWN)
	{
		frac->ymax += frac->cent_y / 100;
		frac->ymin += frac->cent_y / 100;
	}
}

void	set_new_frac(int key, t_fractol *f)
{
	if (key == ONE && f->set != MANDELBROT)
		f->set = MANDELBROT;
	else if (key == TWO && f->set != JULIA)
		f->set = JULIA;
	else if (key == THREE && f->set != CELTIC)
		f->set = CELTIC;
}

void	change_color(t_fractol *frac)
{
	frac->press += 1;
	if (frac->press == 1)
	{
		frac->color_ju = 0.02;
		frac->color1 = 25;
		frac->color2 = 600;
		frac->color3 = 100;
	}
	else if (frac->press == 2)
	{
		frac->color_ju = 0.30;
		frac->color1 = 80;
		frac->color2 = 250;
		frac->color3 = 550;
	}
	else
	{
		frac->color_ju = 0.08;
		frac->color1 = 255;
		frac->color2 = 50;
		frac->color3 = 255;
		frac->press = 0;
	}
}

void	reset_frac(t_fractol *frac)
{
	frac->xmax = 2.5;
	frac->xmin = -2.5;
	frac->ymin = -2.5;
	frac->ymax = frac->ymin + (frac->xmax - frac->xmin) * WIDTH / HEIGHT;
}
