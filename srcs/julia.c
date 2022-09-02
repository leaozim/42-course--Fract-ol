// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   julia.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/08/26 21:44:18 by lade-lim          #+#    #+#             */
// /*   Updated: 2022/08/29 22:25:21 by lade-lim         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../fractol.h"

// void	to_draw_julia(t_fractol *frac)
// {
// 	double temp;
// 	int n;
// 	double aux;
	
// 	aux = 0;
// 	n = 0;
// 	frac->z_real = frac->c_real;
// 	frac->z_imag = frac->c_imag;
// 	while(n < MAX_ITERATIONS && aux < 4)
// 	{
// 		temp = pow(frac->z_real, 2) - pow(frac->z_imag, 2) + frac->c_const_real;
// 		frac->z_imag  = (2 * frac->z_real * frac->z_imag) + frac->c_const_img;
// 		frac->z_real = temp;
// 		aux = pow(frac->z_real, 2) + pow(frac->z_imag, 2);
// 		n++;
// 	}
// 	if(n == MAX_ITERATIONS)
// 		my_mlx_pixel_put(frac,  0x4B0082);
// 	else
// 		my_mlx_pixel_put(frac,  set_color(n));
// }

// int julia(t_fractol *frac)
// {
// 	while (frac->x < WIN_WIDTH)
// 	{
// 		while(frac->y < WIN_HEIGHT)
// 		{
// 			frac->c_real = frac->x_imag + frac->x * (frac->x_real - frac->x_imag)/WIN_WIDTH;
// 			frac->c_imag = frac->y_imag + frac->y * (frac->y_real - frac->y_imag)/WIN_HEIGHT;
// 			to_draw_julia(frac);
// 			frac->y++;
// 		}
// 		frac->x++;
// 		frac->y = 0;
// 	}
// 	return(0);
// }
