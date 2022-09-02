/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:29:38 by lade-lim          #+#    #+#             */
/*   Updated: 2022/08/30 23:38:06 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"

int	set_color(int n)
{
	int	r;
	int	g;
	int	b;
	// double t;

	// t = (double)n / 100;
	// r = (int)(9 * (1 - t) * pow(t, 3) * 255);
 	// g = (int)(15 * pow(1 - t, 2) * pow(t, 2) * 50);
  	// b =  (int)(8.5 * pow(1 - t, 3) * t * 100);
	r = sin(0.08 * n + 10 + 10) * 128 + 127;
	g = sin(0.08 * n + 1 + 52) * 128 + 127;
	b = sin(0.08 * n + 10 + 0) * 128 + 127;
	// r = 250 * t * 1;
	// g = 100* t;
	// b =	256 * t * 10;
	return(r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_fractol *frac, int n)
{
	unsigned int	*dst;

	dst = frac->win_data.addr + (frac->y * frac->win_data.line_length + frac->x * (frac->win_data.bits_per_pixel / 8));
	*(unsigned int *)dst = n;

}