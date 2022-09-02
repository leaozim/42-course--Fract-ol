/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:57:34 by lade-lim          #+#    #+#             */
/*   Updated: 2022/08/24 21:50:53 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"

int	close_game(t_mlx *v)
{
	if (v->win != NULL)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		mlx_destroy_display(v->mlx);
		free(v->mlx);
	}
	exit(0);
}

int	close_esc(int keycode, t_mlx *v)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		mlx_destroy_display(v->mlx);
		free(v->mlx);
		exit(0);
	}
	return (0);
}