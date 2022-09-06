/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:32:12 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/06 22:34:23 by lade-lim         ###   ########.fr       */
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
	win->xmin += (x - 300) * pass;
	win->xmax += (x - 300) * pass;
	win->ymin += (y - 300) * pass;
	win->ymax += (y - 300) * pass;
}




int	mouse_event(int keysys, int x, int y, t_fractol *win)
{
	double	center;
	double	pass;

	center = win->ymax - win->ymin;
	pass = center / 600;
	if (keysys == 4)
	{
		win->xmin += 0.05 * center;
		win->xmax -= 0.05 * center;
		win->ymin += 0.05 * center;
		win->ymax -= 0.05 * center;
		win->max_iterations++;
		move(x, y, win, pass);
	}
	if (keysys == 5)
	{
		win->xmin -= 0.05 * center;
		win->xmax += 0.05 * center;
		win->ymin -= 0.05 * center;
		win->ymax += 0.05 * center;
		win->max_iterations++;
	}
	new_image_draw(win);
	return(0);
}


int	check_fractal(t_fractol *frac, int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp("Mandelbrot", argv[1], 10))
		return (frac->set = MANDELBROT);
	else if (argc >= 2 && !ft_strncmp("Julia", argv[1], 5))
		return (frac->set = JULIA);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	*frac;

	frac = malloc(sizeof(t_fractol));
	if (argc < 2)
		ft_printf("%s\n%s\n", ERRO0, ERRO1);
	if (argc >= 2)
	{
		if (check_fractal(frac, argc, argv))
		{
			init_structs(frac, argc, argv);
			init_window(frac);
		}
		else
			ft_printf("%s\n", ERRO2);
	}
	return (0);
}
