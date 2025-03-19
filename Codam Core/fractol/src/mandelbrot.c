/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 15:55:33 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/19 17:16:23 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot_equation(t_coordinates coordinates);

void	create_mandelbrot_image(mlx_t mandelbrot_window)
{
	mlx_image_t		*img;
	t_coordinates	coordinates;
	int				iterations;

	coordinates.x = WIDTH * 0.1;
	coordinates.y = HEIGHT * 0.1;
	iterations = 0;
	img = mlx_new_image(&mandelbrot_window, WIDTH, HEIGHT);
	while (coordinates.y < (HEIGHT * 0.9))
	{
		coordinates.x = 0;
		while (coordinates.x < (WIDTH * 0.9))
		{
			iterations = mandelbrot_equation(coordinates);
			if (iterations < MAX_ITERATIONS)
				mlx_put_pixel(img, coordinates.x, coordinates.y, 0xFF0000);
			if (iterations == MAX_ITERATIONS)
				mlx_put_pixel(img, coordinates.x, coordinates.y, 0x00FF00);
			coordinates.x++;
		}
		coordinates.y++;
	}
	mlx_image_to_window(&mandelbrot_window, img, 0, 0);
}

int	mandelbrot_equation(t_coordinates coordinates)
{
	t_complex_nbr	complex_nbr;
	double			temp;
	int				i;
	double			temp_real;
	double			temp_imag;

	i = 0;
	temp = 0;
	complex_nbr.real = coordinates.x;
	complex_nbr.imaginary = coordinates.y;
	while ((complex_nbr.real * complex_nbr.real)
		+ (complex_nbr.imaginary * complex_nbr.imaginary)
		<= 4 && i < MAX_ITERATIONS)
	{
		temp_real = complex_nbr.real * complex_nbr.real
			- complex_nbr.imaginary * complex_nbr.imaginary
			+ complex_nbr.real;
		temp_imag = 2 * complex_nbr.real * complex_nbr.imaginary
			+ complex_nbr.imaginary;
		complex_nbr.real = temp_real;
		complex_nbr.imaginary = temp_imag;
		i++;
	}
	return (i);
}
