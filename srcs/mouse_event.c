/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:47:45 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/12 22:07:18 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_event(int keysys, int x, int y, t_fractol *frac)
{
	if (keysys == MOUSE_UP && x)
	{
		frac->xmin += frac->cent_x / 10;
		frac->xmax -= frac->cent_x / 10;
		frac->ymin += frac->cent_y / 10;
		frac->ymax -= frac->cent_y / 10;
		frac->max_iterations += 1;
	}
	if (keysys == MOUSE_DOWN && y)
	{
		frac->xmin -= frac->cent_x / 10;
		frac->xmax += frac->cent_x / 10;
		frac->ymin -= frac->cent_y / 10;
		frac->ymax += frac->cent_y / 10;
	}
	redraw_image(frac);
	return (0);
}
