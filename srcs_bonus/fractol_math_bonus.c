/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:07:37 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/12 22:13:25 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

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

int	julia(t_fractol *frac)
{
	int		n;
	double	temp;
	double	va_z;

	n = 0;
	va_z = 0;
	frac->zmax = frac->cmax;
	frac->zmin = frac->cmin;
	while (n < frac->max_iterations && va_z < 4)
	{
		temp = pow(frac->zmax, 2) - pow(frac->zmin, 2) + frac->kmax;
		frac->zmin = (2 * frac->zmax * frac->zmin) + frac->kmin;
		frac->zmax = temp;
		va_z = pow(frac->zmax, 2) + pow(frac->zmin, 2);
		n++;
	}
	return (n);
}

int	celtic(t_fractol *frac)
{
	int		n;

	n = 0;
	frac->zmax = 0;
	frac->zmin = 0;
	frac->sqr_zmax = frac->zmax * frac->zmax;
	frac->sqr_zmin = frac->zmin * frac->zmin;
	while (n < frac->max_iterations && frac->sqr_zmax + frac->sqr_zmin < 4)
	{
		frac->zmin = (2 * frac->zmax * frac->zmin) + frac->cmin;
		frac->zmax = fabs(frac->sqr_zmax - frac->sqr_zmin) + frac->cmax;
		frac->sqr_zmax = pow(frac->zmax, 2);
		frac->sqr_zmin = pow(frac->zmin, 2);
		n++;
	}
	return (n);
}
