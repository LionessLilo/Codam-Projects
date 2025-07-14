/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 15:00:37 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/27 11:44:36 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	void		*mlx;
	void		*image;
	int			image_instance;
	int			window_width;
	int			window_height;
	float		real_max;
	float		real_min;
	float		imag_max;
	float		imag_min;
	int			max_iter;
	float		zoom;
}				t_data;

typedef struct s_complex_coord
{
	int		pixel_x;
	int		pixel_y;
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
}			t_complex_coord;


void			init_data(t_data *data);
t_complex_coord	pixels_to_complex(t_data data, t_complex_coord coords);
long int				mandelbrot(t_complex_coord coords,t_data data);
void			place_pixels(int iterations, t_complex_coord coordinates,
					t_data data);
void			display_mandelbrot(t_data data);
void			handle_scroll(double x_scroll,
					double y_scroll, void *own_param);
void			draw_mandelbrot(t_complex_coord coordinates, t_data data);

#endif