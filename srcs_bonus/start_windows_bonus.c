/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_windows_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:57:34 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/12 20:01:02 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	init_window(t_fractol *f)
{
	f->w_data.mlx = mlx_init();
	check_mlx(f, f->w_data.mlx);
	f->w_data.win = mlx_new_window(f->w_data.mlx, WIDTH, HEIGHT, "Fract-ol!");
	check_mlx(f, f->w_data.win);
	init_image(f);
	mlx_mouse_hook(f->w_data.win, &mouse_event, f);
	mlx_hook(f->w_data.win, KEY_PRESS, KEY_PRESS_MASK, &keyboard_events, f);
	mlx_hook(f->w_data.win, DESTROY_NOTIFY, NO_EVENT_MASK, &close_window, f);
	mlx_loop(f->w_data.mlx);
}

void	init_image(t_fractol *f)
{
	f->w_data.img = mlx_new_image(f->w_data.mlx, WIDTH, HEIGHT);
	f->w_data.addr = mlx_get_data_addr(f->w_data.img, &f->w_data.bit_per_pixel, \
	&f->w_data.line_length, &f->w_data.endian);
	draw_fractol(f);
	mlx_put_image_to_window(f->w_data.mlx, f->w_data.win, f->w_data.img, 0, 0);
	menu(f);
}

void	menu(t_fractol *v)
{
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 45, CLR, "Controls");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 54, CLR, "-------------");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 63, CLR, "Move: ARROWS");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 78, CLR, "Color: C");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 93, CLR, "Zoom: SCROLL");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 108, CLR, "Reset: R");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 123, CLR, "Exit: ESC");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 133, CLR, "-------------");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 537, CLR, "Fract's");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 546, CLR, "-------------");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 555, CLR, "1: Mandelbrot");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 570, CLR, "2: Julia");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 585, CLR, "3: Celtic");
	mlx_string_put(v->w_data.mlx, v->w_data.win, 37, 595, CLR, "-------------");
}
