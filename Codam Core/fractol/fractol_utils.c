/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/21 13:05:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/21 13:29:32 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void			zoom_in(t_data *zoom_data);
void			zoom_out(t_data *zoom_data);
t_complex_coord	pixels_to_complex(t_pixels pixels, t_data data);
void			clear_image(t_window window);


void	zoom_in(t_data *zoom_data)
{
	double	zoom_amount;
	double	centre_real;
	double	centre_imag;
	double	range_real;
	double	range_imag;

	zoom_amount = 1.5;
	centre_real = (zoom_data->real_min + zoom_data->real_max) / 2;
	centre_imag = (zoom_data->imag_min + zoom_data->imag_max) / 2;
	range_real = (zoom_data->real_max - zoom_data->real_min) / zoom_amount;
	range_imag = (zoom_data->imag_max - zoom_data->imag_min) / zoom_amount;
	zoom_data->real_min = centre_real - range_real / 2;
	zoom_data->real_max = centre_real + range_real / 2;
	zoom_data->imag_min = centre_imag - range_imag / 2;
	zoom_data->imag_max = centre_imag + range_imag / 2;
}

void	zoom_out(t_data *zoom_data)
{
	double	zoom_amount;
	double	centre_real;
	double	centre_imag;
	double	range_real;
	double	range_imag;

	zoom_amount = 1.5;
	centre_real = (zoom_data->real_min + zoom_data->real_max) / 2;
	centre_imag = (zoom_data->imag_min + zoom_data->imag_max) / 2;
	range_real = (zoom_data->real_max - zoom_data->real_min) * zoom_amount;
	range_imag = (zoom_data->imag_max - zoom_data->imag_min) * zoom_amount;
	zoom_data->real_min = centre_real - range_real * 2;
	zoom_data->real_max = centre_real + range_real * 2;
	zoom_data->imag_min = centre_imag - range_imag * 2;
	zoom_data->imag_max = centre_imag + range_imag * 2;
}

t_complex_coord	pixels_to_complex(
	t_pixels pixels,
	t_data data
)
{
	t_complex_coord	coords;

	coords.c_real = data.real_min + pixels.x
		*(data.real_max - data.real_min) / data.window_width;
	coords.c_imag = data.imag_max - pixels.y
		* (data.imag_max - data.imag_min) / data.window_height;
	return (coords);
}

void	handle_scroll(
	double x_scroll,
	double y_scroll,
	void *own_param,
	void *window
)
{
	t_data		*zoom_data;

	(void)x_scroll;
	zoom_data = (t_data *)own_param;
	if (y_scroll > 0)
		zoom_in(zoom_data);
	else if (y_scroll < 0)
		zoom_out(zoom_data);
	clear_image((t_window *)window);
}

void	clear_image(t_window window)
{
	int	x;
	int	y;

	while (y < data.window_height
		&& pixels.y < (int)((mlx_image_t *)window.image)->height)
	{
		pixels.x = 0;
		while (pixels.x < data.window_width
			&& pixels.x < (int)((mlx_image_t *)window.image)->width)
		{
			iterations = mandelbrot(pixels, data);
			place_pixels(iterations, window, pixels, data);
			pixels.x++;
		}
		pixels.y++;
	}
}
