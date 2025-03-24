/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 15:55:33 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/21 18:43:27 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	iterations(t_coordinates s_coordinates);

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

int	iterations(t_coordinates s_coordinates)
{
	bool			is_inside;
	static int		iterations_nbr;

	find_new_coordinates(s_coordinates);
	is_inside = inside_mandelbrot(s_coordinates);
	if (is_inside == true && iterations_nbr < MAX_ITERATIONS)
	{
		iterations_nbr++;
		iterations(s_coordinates);
	}
	else if (is_inside == false && iterations_nbr < MAX_ITERATIONS)
		return (iterations_nbr);
	else
		return (MAX_ITERATIONS);
}
