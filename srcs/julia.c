/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:20:32 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/05 21:35:18 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
