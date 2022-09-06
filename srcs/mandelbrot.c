/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:21:17 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/06 16:34:39 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_fractol *frac)
{
	int		n;
	double	temp;
	double	va_z;

	va_z = 0;
	n = 0;
	frac->zmax = frac->cmax;
	frac->zmin = frac->cmin;
	while (n < frac->max_iterations && va_z < 4)
	{
		temp = pow(frac->zmax, 2) - pow(frac->zmin, 2) + frac->cmax;
		frac->zmin = (2 * frac->zmax * frac->zmin) + frac->cmin;
		frac->zmax = temp;
		va_z = pow(frac->zmax, 2) + pow(frac->zmin, 2);
		n++;
	}
	return (n);
}
