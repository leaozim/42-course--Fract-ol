/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:32:20 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/11 16:50:46 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	keyboard_events(int key, t_fractol *f)
{
	printf("%d\n", key);
	if (key == ESC)
		close_win(f);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		fractol_move(key, f);
	else if (key == ONE || key == TWO || key == THREE)
		set_new_frac(key, f);
	else if (key == C)
		change_color(f);
	else if(key == R)
		reset_frac(f);
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
	frac->color_ju = 0.80;
	frac->color1 = 256;
	frac->color2 = 50;
	frac->color3 = 255;
}

void	reset_frac(t_fractol *data)
{
	data->color_ju = 0.08;
	data->color1 = 255;
	data->color2 = 50;
	data->color3 = 100;
	data->xmax = 2.5;
	data->xmin = -2.5;
	data->ymin = -2.5;
	data->ymax = data->ymin + (data->xmax - data->xmin) * WIDTH / HEIGHT;
}