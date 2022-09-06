/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:57:34 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/06 20:20:47 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_window(t_fractol *f)
{
	f->w_data.mlx = mlx_init();
	f->w_data.win = mlx_new_window(f->w_data.mlx, WIDTH, HEIGHT, "Fract-ol!");
	init_image(f);
	mlx_mouse_hook(f->w_data.win, &mouse_event, f);
	mlx_hook(f->w_data.win, KeyPress, KeyPressMask, &close_esc, f);
	mlx_hook(f->w_data.win, DestroyNotify, NoEventMask, &close_game, f);
	mlx_loop(f->w_data.mlx);
}

void	init_image(t_fractol *f)
{
	f->w_data.img = mlx_new_image(f->w_data.mlx, WIDTH, HEIGHT);
	f->w_data.addr = mlx_get_data_addr(f->w_data.img, &f->w_data.bit_per_pixel, \
	&f->w_data.line_length, &f->w_data.endian);
	draw_fractol(f);
	mlx_put_image_to_window(f->w_data.mlx, f->w_data.win, f->w_data.img, 0, 0);
}

void	new_image_draw(t_fractol *f)
{
	mlx_clear_window(f->w_data.mlx, f->w_data.win);
	draw_fractol(f);
	mlx_put_image_to_window(f->w_data.mlx, f->w_data.win, f->w_data.img, 0, 0);
}

int	close_game(t_fractol *f)
{
	if (f->w_data.win != NULL)
	{
		mlx_destroy_image(f->w_data.mlx, f->w_data.img);
		mlx_destroy_window(f->w_data.mlx, f->w_data.win);
		mlx_destroy_display(f->w_data.mlx);
		free(f->w_data.mlx);
		free(f);
	}
	exit (0);
}

int	close_esc(int keycode, t_fractol *f)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(f->w_data.mlx, f->w_data.img);
		mlx_destroy_window(f->w_data.mlx, f->w_data.win);
		mlx_destroy_display(f->w_data.mlx);
		free(f->w_data.mlx);
		exit(0);
		free(f);
	}
	return (0);
}
