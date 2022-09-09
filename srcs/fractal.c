/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:32:12 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/07 20:11:48 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	check_fractal(t_fractol *frac, int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp("Mandelbrot", argv[1], 10))
		return (frac->set = MANDELBROT);
	else if (argc >= 2 && !ft_strncmp("Julia", argv[1], 5))
		return (frac->set = JULIA);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	*frac;

	frac = malloc(sizeof(t_fractol));
	if (argc < 2)
		ft_printf("%s\n%s\n", ERRO0, ERRO1);
	if (argc >= 2)
	{
		if (check_fractal(frac, argc, argv))
		{
			init_structs(frac, argc, argv);
			init_window(frac);
		}
		else
			ft_printf("%s\n", ERRO2);
	}
	return (0);
}
