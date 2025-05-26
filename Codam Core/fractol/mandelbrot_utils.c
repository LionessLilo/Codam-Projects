/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 17:45:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/26 16:24:47 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	init_data(t_data *data);

/* Translates pixel to complex number. Gives me the value of c at pixel (x,y) */
t_complex_coord	pixels_to_complex(t_pixels pixels, t_data data)
{
	t_complex_coord	coords;

	coords.c_real = data.real_min + pixels.x
		*(data.real_max - data.real_min) / data.window_width;
	coords.c_imag = data.imag_max - pixels.y 
		* (data.imag_max - data.imag_min) / data.window_height;
	return (coords);
}

// void	scroll(double x_scroll, double y_scroll, void *own_param)
// {
// 	(void)x_scroll;
// 	(void)own_param;
// 	if (y_scroll > 0)
// 		zoom_in();
// 	else if (y_scroll < 0)
// 		zoom_out();
// }

void	init_data(t_data *data)
{
	data->window_width = 800;
	data->window_height = 600;
	data->real_max = 1.0;
	data->real_min = -2.0;
	data->imag_max = 1.5;
	data->imag_min = -1.5;
	data->max_iter = 150;
}