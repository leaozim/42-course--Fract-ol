/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:47:45 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/12 20:00:55 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

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
