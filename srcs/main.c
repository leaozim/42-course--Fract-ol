/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:32:12 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/02 22:34:49 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>
#include <unistd.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

void	move(int x, int y, t_fractol *win, double pass)
{
	win->x_im += (x - 300) * pass;
	win->x_re += (x - 300) * pass;
	win->y_im += (y - 300) * pass;
	win->y_re += (y - 300) * pass;
}

int	mouse_event(int keysys, int x, int y, t_fractol *win)
{
	double	center_im;
	double	center_re;
	double	pass;

	center_im = win->x_re - win->x_im;
	pass = center_im / 600;
	if (keysys == 4)
	{
		printf("antes:%d-->\t(%d,%d)\n", keysys, x, y);
		win->x_im += 0.05 * center_im;
		win->x_re -= 0.05 * center_im;
		win->y_im += 0.05 * center_im;
		win->y_re -= 0.05 * center_im;
		win->max_iterations++;
		move(x, y, win, pass);
	}
	if (keysys == 5)
	{
		win->x_im -= 0.05 * center_im;
		win->x_re += 0.05 * center_im;
		win->y_im -= 0.05 * center_im;
		win->y_re += 0.05 * center_im;
		win->max_iterations++;
	}
	start_image(win);
	return(0);
}



void	start_image(t_fractol *frac)
{
	frac->win_data.img = mlx_new_image(frac->win_data.mlx, WIN_WIDTH - MENU_WIN, WIN_HEIGHT);	
	frac->win_data.addr = mlx_get_data_addr(frac->win_data.img, &frac->win_data.bits_per_pixel, \
	&frac->win_data.line_length, &frac->win_data.endian);
	// mlx_clear_window(frac->win_data.mlx, frac->win_data.win);
	mandelbrot(frac);
	// julia(frac);
	mlx_put_image_to_window(frac->win_data.mlx, frac->win_data.win, frac->win_data.img, 0, 0);
}

int main(void)
{
	t_fractol	frac;

	init_structs(&frac);
	frac.win_data.mlx = mlx_init();
	frac.win_data.win = mlx_new_window(frac.win_data.mlx, WIN_WIDTH - MENU_WIN, WIN_HEIGHT, "Fract's!");
	start_image(&frac);
	mlx_mouse_hook(frac.win_data.win, mouse_event, &frac);
	mlx_hook(frac.win_data.win, KeyPress, KeyPressMask, &close_esc, &frac);
	mlx_hook(frac.win_data.win, DestroyNotify, NoEventMask, &close_game, &frac);
	mlx_loop(frac.win_data.mlx);
}
