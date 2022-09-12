/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:42:20 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/12 02:43:07 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_win(t_fractol *f)
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
