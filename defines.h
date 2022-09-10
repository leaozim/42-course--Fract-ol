/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:32:27 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/10 19:30:05 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define ONE 65436
# define TWO 65433
# define THREE 65435
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define DESTROY_NOTIFY 17
# define NO_EVENT_MASK	0L
# define KEY_PRESS 02
# define KEY_PRESS_MASK 1L<<0

# define CLR 0xFFFFF

# define MANDELBROT 1
# define JULIA 2
# define CELTIC 3

# define WIDTH 600
# define HEIGHT 600

# define ERRO0 "Invalid number of parameters."
# define ERRO1 "Usage: ./fractol (Julia / Mandelbrot)"
# define ERRO2 "Is not a valid fractal name."

#endif