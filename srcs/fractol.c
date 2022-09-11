/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:32:12 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/11 22:59:35 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	check_error(t_fractol *frac, int argc, char **argv)
{
	if (argc < 2 || argc > 4 || argc == 3)
		return(ft_printf("%s%s%s", ERR0, ERR1, ERR2), 1);
	if (argc == 2 && !ft_strncmp("Julia", argv[1], 5))
		return(ft_printf("%s%s%s", ERR0, ERR1, ERR3), 1); 
	if (frac->set != JULIA && frac->set != MANDELBROT && frac->set != CELTIC)
		return(ft_printf("%s", ERR4), 1);
	return (0);
}

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
	if( !(check_error(frac, argc, argv)))
	{
		init_structs(frac, argc, argv);
		init_window(frac);
	}
	return (0);
}
