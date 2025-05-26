/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 15:00:37 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/21 13:27:57 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_window
{
	void	*mlx;
	void	*image;
	int		image_instance;
}			t_window;
typedef struct s_zoom
{
	t_window	*window;
	double		zoom;
}				t_zoom;

typedef struct s_data
{
	int			window_width;
	int			window_height;
	float		real_max;
	float		real_min;
	float		imag_max;
	float		imag_min;
	int			max_iter;
	t_zoom		*zoom;
}				t_data;


typedef struct s_pixels
{
	int	x;
	int	y;
}		t_pixels;

typedef struct s_complex_coord
{
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
}			t_complex_coord;


void			init_data(t_data *data);
t_complex_coord	pixels_to_complex(t_pixels pixels, t_data data);
int				mandelbrot(t_pixels pixels, t_data data);
void			place_pixels(int iterations, t_window window,
					t_pixels pixels, t_data data);
void			display_mandelbrot(t_data data);
void			handle_scroll(double x_scroll,
					double y_scroll, void *own_param, void *window);
void			draw_mandelbrot(t_pixels pixels, t_window window, t_data data);

#endif