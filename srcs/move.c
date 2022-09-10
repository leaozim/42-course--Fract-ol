/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:32:20 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/10 19:59:45 by lade-lim         ###   ########.fr       */
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
	else if (key == 99)
		change_color(f);
	return (0);
}

int	mouse_event(int keysys, int x, int y, t_fractol *frac)
{
	if (keysys == MOUSE_UP)
	{
		frac->xmin += frac->cent_x * (x / (double)WIDTH) / 5;
		frac->xmax -= frac->cent_x * (1 - x / (double)WIDTH) / 5;
		frac->ymin += frac->cent_y * (y / (double)HEIGHT) / 5;
		frac->ymax -= frac->cent_y * (1 - y / (double)HEIGHT) / 5;
		frac->max_iterations += 30;
	}
	if (keysys == MOUSE_DOWN)
	{
		frac->xmin -= frac->cent_x * (x / (double)WIDTH) / 5;
		frac->xmax += frac->cent_x * (1 - x / (double)WIDTH) / 5;
		frac->ymin -= frac->cent_y * (y / (double)HEIGHT) / 5;
		frac->ymax += frac->cent_y * (1 - y / (double)HEIGHT) / 5;
	}
	redraw_image(frac);
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
	redraw_image(frac);
}

void	set_new_frac(int key, t_fractol *f)
{
	if (key == ONE && f->set != MANDELBROT)
		f->set = MANDELBROT;
	else if (key == TWO && f->set != JULIA)
		f->set = JULIA;
	else if (key == THREE && f->set != CELTIC)
		f->set = CELTIC;
	redraw_image(f);
}
