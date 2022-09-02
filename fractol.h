/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:53:40 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/02 21:38:52 by lade-lim         ###   ########.fr       */
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
	double	x_re;
	double	x_im;
	double	y_re;
	double	y_im;
	double	z_re;
	double	z_im;
	double	c_re;
	double	c_im;
	double	k_re;
	double	k_im;
	t_mlx	win_data;
	double	max_iterations;
}				t_fractol;


int		main(void);
void	init_structs(t_fractol *frac);
int		close_game(t_mlx *v);
int		close_esc(int keycode, t_mlx *v);
int		to_draw_mandelbrot(t_fractol *frac);
int		mandelbrot(t_fractol *frac);
int		set_color(int n);
void	my_mlx_pixel_put(t_fractol *frac, int n);
int		to_draw_julia(t_fractol *frac);
int		julia(t_fractol *frac);
void	start_image(t_fractol *frac);



#endif