/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 16:33:09 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/14 16:14:30 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	place_pixels(int iterations, t_window window, t_pixels pixels);

/* 
	Takes the complex numbers converted from the pixel coordinates,
	runs it through the mandelbrot equation and returns 
	the number of iterations
*/
int	mandelbrot(t_pixels pixels)
{
	t_complex_coord	coords;
	int				iterations;
	double			temp;

	iterations = 0;
	coords = pixels_to_complex(pixels);
	coords.z_real = 0;
	coords.z_imag = 0;
	while (coords.z_real * coords.z_real + coords.z_imag * coords.z_imag <= 4
		&& iterations < MAX_ITER)
	{
		temp = coords.z_real * coords.z_real
			- coords.z_imag * coords.z_imag + coords.c_real;
		coords.z_imag = 2 * coords.z_real * coords.z_imag + coords.c_imag;
		coords.z_real = temp;
		iterations++;
	}
	return (iterations);
}

void	place_pixels(int iterations, t_window window, t_pixels pixels)
{
	uint32_t	color;

	if (iterations == MAX_ITER)
		color = 0x272643FF;
	else if (iterations >= MAX_ITER / 2)
		color = 0xe3f6f5FF;
	else if (iterations >= MAX_ITER / 4)
		color = 0xbae8e8FF;
	else if (iterations >= MAX_ITER / 16)
		color = 0x2c698dFF;
	else
		color = 0x8d2c66FF;
	mlx_put_pixel(window.image, pixels.x, pixels.y, color);
}
