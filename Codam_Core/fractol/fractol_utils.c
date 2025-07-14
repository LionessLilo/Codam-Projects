/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/21 13:05:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/27 11:45:23 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void			zoom_in(t_data *zoom_data);
void			zoom_out(t_data *zoom_data);
t_complex_coord	pixels_to_complex(t_data data, t_complex_coord coords);
void			clear_image(t_data *data);


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

t_complex_coord	pixels_to_complex(t_data data, t_complex_coord coords)
{

	coords.c_real = data.real_min + coords.pixel_x
		*(data.real_max - data.real_min) / data.window_width;
	coords.c_imag = data.imag_max - coords.pixel_y
		* (data.imag_max - data.imag_min) / data.window_height;
	return (coords);
}

void	handle_scroll(
	double x_scroll,
	double y_scroll,
	void *own_param
){
	t_complex_coord	*coordinates;
	t_data			*zoom_data;

	(void)x_scroll;
	coordinates = (t_complex_coord *)own_param;
	zoom_data = (t_data *)(long int)own_param;
	if (y_scroll > 0)
		zoom_in(zoom_data);
	else if (y_scroll < 0)
		zoom_out(zoom_data);
	clear_image(zoom_data);
	draw_mandelbrot(*coordinates, *zoom_data);
}

void	clear_image(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->window_height)
	{
		x = 0;
		while (x < data->window_width)
		{
			mlx_put_pixel(data->image, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}
