/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 16:33:09 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/27 11:52:34 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	draw_mandelbrot(t_complex_coord coordinates, t_data data);
void	display_mandelbrot(t_data data);
void	place_pixels(int iterations, t_complex_coord coordinates, t_data data);

/* 
	Takes the complex numbers converted from the pixel coordinates,
	runs it through the mandelbrot equation and returns 
	the number of iterations
*/
long int	mandelbrot(t_complex_coord coords, t_data data)
{
	long int		iterations;
	double			temp;

	iterations = 0;
	coords = pixels_to_complex(data, coords);
	coords.z_real = 0;
	coords.z_imag = 0;
	while (coords.z_real * coords.z_real + coords.z_imag * coords.z_imag <= 4
		&& iterations < data.max_iter)
	{
		temp = coords.z_real * coords.z_real
			- coords.z_imag * coords.z_imag + coords.c_real;
		coords.z_imag = 2 * coords.z_real * coords.z_imag + coords.c_imag;
		coords.z_real = temp;
		iterations++;
	}
	return (iterations);
}

/* It takes the current pixel and the number of iterations produced from 
	the mandelbrot formula. It gives the pixel a colour based on the number 
	of iterations. 
*/
void	place_pixels(
	int iterations,
	t_complex_coord coordinates,
	t_data data
)
{
	uint32_t	color;

	if (iterations == data.max_iter)
		color = 0x272643FF;
	else if (iterations >= data.max_iter / 2)
		color = 0xe3f6f5FF;
	else if (iterations >= data.max_iter / 4)
		color = 0xbae8e8FF;
	else if (iterations >= data.max_iter / 16)
		color = 0x2c698dFF;
	else
		color = 0x8d2c66FF;
	mlx_put_pixel(data.image, coordinates.pixel_x, coordinates.pixel_y, color);
}

/* It creates the window and the instance for the mandelbrot, draws the 
	mandelbrot, put that image to the window, handlesthe scroll and 
	keeps the window open until the instance is terminated. 
*/
void	display_mandelbrot(t_data data)
{
	t_complex_coord	coordinates;

	data.mlx = mlx_init(data.window_width, data.window_height,
			"fractol", false);
	data.image = mlx_new_image(data.mlx, data.window_width,
			data.window_height);
	draw_mandelbrot(coordinates, data);
	data.image_instance = mlx_image_to_window(data.mlx, data.image, 0, 0);
	mlx_scroll_hook(data.mlx, (void *)handle_scroll, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}

/* Draws the image created by putting each pixel through the mandelbrot 
	formula.
*/
void	draw_mandelbrot(
	t_complex_coord coordinates,
	t_data data
)
{
	int			iterations;

	coordinates.pixel_y = 0;
	while (coordinates.pixel_y < data.window_height
		&& coordinates.pixel_y < (int)((mlx_image_t *)data.image)->height)
	{
		coordinates.pixel_x = 0;
		while (coordinates.pixel_x < data.window_width
			&& coordinates.pixel_x < (int)((mlx_image_t *)data.image)->width)
		{
			iterations = mandelbrot(coordinates, data);
			place_pixels(iterations, coordinates, data);
			coordinates.pixel_x++;
		}
		coordinates.pixel_y++;
	}
}
