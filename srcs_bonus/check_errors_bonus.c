/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:10:08 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/12 19:59:56 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	check_mlx(t_fractol *f, t_fractol *window_data)
{
	if (!window_data)
	{
		free (f);
		exit (0);
	}
}

int	check_args(t_fractol *frac, int argc, char **argv)
{
	if (argc < 2 || argc > 4 || argc == 3)
		return (ft_printf("%s%s%s", MSG0, MSG1, MSG2), ERROR);
	if (argc == 2 && !ft_strncmp("Julia", argv[1], 5))
		return (ft_printf("%s%s%s", MSG0, MSG1, MSG3), ERROR);
	if (frac->set != JULIA && frac->set != MANDELBROT && frac->set != CELTIC)
		return (ft_printf("%s", MSG4), ERROR);
	return (SUCES);
}
