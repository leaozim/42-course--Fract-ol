/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:32:12 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/15 00:59:42 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	define_fractol(t_fractol *frac, int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp("Mandelbrot", argv[1], 10))
		return (frac->set = MANDELBROT);
	else if (argc == 4 && !ft_strncmp("Julia", argv[1], 5) \
	&& ft_isnum(argv[2]) && ft_isnum(argv[3]))
		return (frac->set = JULIA);
	else if (argc == 2 && !ft_strncmp("Celtic", argv[1], 10))
		return (frac->set = CELTIC);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	*frac;

	frac = malloc(sizeof(t_fractol));
	define_fractol(frac, argc, argv);
	if (!(check_args(frac, argc, argv)))
	{
		init_structs(frac, argv);
		init_window(frac);
	}
	free (frac);
	return (0);
}
