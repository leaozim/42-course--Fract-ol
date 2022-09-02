/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:53:40 by lade-lim          #+#    #+#             */
/*   Updated: 2022/08/31 23:32:53 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "./my_libs/ft_libft/libft.h"	
# include "./my_libs/ft_printf/ft_printf.h"

#define MAX_ITERATIONS 100


# define WIN_WIDTH 600
# define WIN_HEIGHT 600

# define FRAC_WW 600
# define FRAC_WH 600

# define MENU_WIN 0

typedef struct	s_mlx 
{
	void	*mlx;
	void	*mlx_win;
	void	*win;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*addr;
	void	*path;
}				t_mlx;

typedef struct	s_fractol
{
	int		x;
	int		y;
	double	x_real;
	double	x_imag;
	double	y_real;
	double	y_imag;
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
	double	c_const_real;
	double	c_const_img;
	t_mlx	win_data;
	double	max_iterations;
}				t_fractol;


int		main(void);
void	start_mandelbrot(t_fractol *frac);
int		close_game(t_mlx *v);
int		close_esc(int keycode, t_mlx *v);
int		to_draw_mandelbrot(t_fractol *frac);
int		mandelbrot(t_fractol *frac);
int		set_color(int n);
void	my_mlx_pixel_put(t_fractol *frac, int n);
void	to_draw_julia(t_fractol *frac);
int		julia(t_fractol *frac);
void	start_image(t_fractol *frac);



#endif