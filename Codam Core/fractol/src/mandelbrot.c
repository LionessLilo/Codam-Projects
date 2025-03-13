/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 15:55:33 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/13 16:21:44 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	create_mandelbrot_image(double x_coordinate,
								double y_coordinate,
								mlx_image_t *canvas)
{
	while (y_coordinate < (HEIGHT * 0.9))
	{
		while(x_coordinate < (WIDTH * 0.9))
			convert_to_complex_numbers(x_coordinate, y_coordinate);
		y_coordinate++;
	}
}

void	convert_to_complex_numbers(double x_coordinate,
									double y_coordinate)
{
	double	real_number;
	double	imaginary_number;
	double	complex_number;

	real_number = 0;
	imaginary_number = 0;
	complex_number = 0;
	real_number = -2 + (x_coordinate)
}
