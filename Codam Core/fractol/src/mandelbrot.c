/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 15:55:33 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/24 18:41:49 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	iterations(t_coordinates coordinates);

void	create_mandelbrot_image(mlx_t mandelbrot_window)
{
	mlx_image_t		*img;

	img = mlx_new_image(&mandelbrot_window, WIDTH, HEIGHT);
	/*
	TO DO
	For each cell and row
		get co-ordinates
		Feed coords into coordinate functions
		draw based on results
	*/
	mlx_image_to_window(&mandelbrot_window, img, 0, 0);
}

int	iterations(t_coordinates coordinates)
{
	bool	is_inside;
	int		iterations_nbr;

	iterations_nbr = 0;
	while (iterations_nbr < MAX_ITERATIONS)
	{
		is_inside = inside_mandelbrot(coordinates);
		if (is_inside == false)
			return (iterations_nbr);
		iterations_nbr++;
		find_new_coordinates(&coordinates);
	}
	return (MAX_ITERATIONS);
}
