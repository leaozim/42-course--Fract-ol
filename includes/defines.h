/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:32:27 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/12 18:24:16 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define ONE 65436
# define TWO 65433
# define THREE 65435
# define C 99
# define R 114
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

# define MSG0 "-----------------------------------"
# define MSG1 "\nInvalid passed parameters.\nDo like this: \n"
# define MSG2 "\t./fractol Mandelbrot\n\
\t./fractol Julia [X.XXX][X.XXX]\n\t./fractol Celtic\n"
# define MSG3 "./Julia [X.XXX][X.XXX]\nEx:\n\t0.37\t 0.1 \
\n\t0.355\t 0.355\n\t-0.4\t-0.9\n\t0,355534 0,337292\n"
# define MSG4 "This is not a valid parameter.\n"

# define ERROR 1
# define SUCES 0

#endif