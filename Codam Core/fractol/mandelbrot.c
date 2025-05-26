/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 16:33:09 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/21 13:02:30 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	draw_image(t_pixels pixels, t_window window, t_data data);
void	display_mandelbrot(t_data data);
void	place_pixels(int iterations, t_window window,
			t_pixels pixels, t_data data);

/* 
	Takes the complex numbers converted from the pixel coordinates,
	runs it through the mandelbrot equation and returns 
	the number of iterations
*/
int	mandelbrot(
	t_pixels pixels,
	t_data data
)
{
	t_complex_coord	coords;
	int				iterations;
	double			temp;

	iterations = 0;
	coords = pixels_to_complex(pixels, data);
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

void	place_pixels(
	int iterations,
	t_window window,
	t_pixels pixels,
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
	mlx_put_pixel(window.image, pixels.x, pixels.y, color);
}

void	display_mandelbrot(t_data data)
{
	t_window	window;
	t_pixels	pixels;

	window.mlx = mlx_init(data.window_width, data.window_height,
			"fractol", false);
	window.image = mlx_new_image(window.mlx, data.window_width,
			data.window_height);
	pixels.y = 0;
	draw_image(pixels, window, data);
	window.image_instance = mlx_image_to_window(window.mlx, window.image, 0, 0);
	mlx_scroll_hook(window.mlx, (void *)handle_scroll, &data);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
}

void	draw_mandelbrot(
	t_pixels pixels,
	t_window window,
	t_data data
)
{
	int			iterations;

	while (pixels.y < data.window_height
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
