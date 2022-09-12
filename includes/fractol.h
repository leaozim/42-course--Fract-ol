/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:53:40 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/12 19:09:53 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "defines.h" 
# include "../my_libs/ft_libft/libft.h"	
# include "../my_libs/ft_printf/ft_printf.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
	void	*addr;
}	t_mlx;

typedef struct s_fractol
{
	int		x;
	int		y;
	int		set;
	int		n;
	int		color1;
	int		color2;
	int		color3;
	int		max_iterations;
	int		press;
	double	color_ju;
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
	double	zmax;
	double	zmin;
	double	cmax;
	double	cmin;
	double	kmax;
	double	kmin;
	double	sqr_zmax;
	double	sqr_zmin;
	double	cent_x;
	double	cent_y;
	t_mlx	w_data;
}	t_fractol;

int			main(int argc, char **argv);
int			define_fractol(t_fractol *frac, int argc, char **argv);
int			check_args(t_fractol *frac, int argc, char **argv);
void		init_structs(t_fractol *data, int argc, char **argv);
void		init_julia(t_fractol *frac, int argc, char **argv);
void		init_window(t_fractol *f);
void		init_image(t_fractol *frac);
void		check_mlx(t_fractol *f, t_fractol *window_data);
void		menu(t_fractol *v);
int			draw_fractol(t_fractol *frac);
void		set_frac_color(t_fractol *frac, int n);
void		my_mlx_pixel_put(t_fractol *frac, int n);
int			set_color(t_fractol *frac, int n);
void		redraw_image(t_fractol *f);
int			mandelbrot(t_fractol *frac);
int			julia(t_fractol *frac);
int			celtic(t_fractol *frac);
int			keyboard_events(int key, t_fractol *f);
int			check_fractol(t_fractol *frac, int argc, char **argv);
int			mouse_event(int keysys, int x, int y, t_fractol *win);
void		fractol_move(int key, t_fractol *frac);
void		set_new_frac(int key, t_fractol *f);
void		change_color(t_fractol *data);
void		reset_frac(t_fractol *data);
int			close_window(t_fractol *f);

#endif