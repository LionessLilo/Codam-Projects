/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coordinate_functions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/21 18:04:35 by lilo          #+#    #+#                 */
/*   Updated: 2025/03/24 18:42:04 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	log_tick(void)
{
	printf("\033[0;32m ✔ \033[0;37m \n");
}

// static void	log_cross(void)
// {
// 	printf("\033[0;31m 🗶 \033[0;37m \n");
// }

static void	log_error(char *message)
{
	printf("\033[0;31m%s\n\n\033[0;37m", message);
}

int	main(void)
{
	t_coordinates	coordinates;
	bool			is_inside_manedelbrot;
	int				nbr_iterations;

	// Defs in mandelbrot:
	coordinates.x_coord = 1.4;
	coordinates.y_coord = 1.4;
	is_inside_manedelbrot = inside_mandelbrot(coordinates);
	if (is_inside_manedelbrot == true)
	{
		printf("\033[0;37mControl | is inside Mandelbrot: ");
		log_tick();
	}
	else
		log_error("Control failed\n");

	// Defs out mandelbrot
	coordinates.x_coord = 1.5;
	coordinates.y_coord = 1.5;
	is_inside_manedelbrot = inside_mandelbrot(coordinates);
	if (is_inside_manedelbrot == false)
	{
		printf("\033[0;37mControl | is outside Mandelbrot ");
		log_tick();
	}
	else
		log_error("Control failed\n");

	// Find new coordinates, outside mandelbrot
	coordinates.x_coord = 1.4;
	coordinates.y_coord = 1.4;
	find_new_coordinates(&coordinates);
	is_inside_manedelbrot = inside_mandelbrot(coordinates);
	if (is_inside_manedelbrot == false)
	{
		printf("\033[0;37mFind new coordinates function works: ");
		log_tick();
	}
	else
		log_error("New coordinates function has an issue\n");

	// Find new coordinates, in mandelbrot
	coordinates.x_coord = 0.3;
	coordinates.y_coord = 0.3;
	find_new_coordinates(&coordinates);
	if (coordinates.x_coord == 0.300000 && coordinates.y_coord == 0.480000)
	{
		printf("Find new coordinates is working");
		log_tick();
	}
	else
	{
		log_error("Find new coordinates failed");
		printf("%f %f", coordinates.x_coord, coordinates.y_coord);
	}

	// Iterations
	coordinates.x_coord = 0.5;
	coordinates.y_coord = 0.5;
	nbr_iterations = iterations(coordinates);
	if (nbr_iterations == 2)
	{
		printf("Iteration function works");
		log_tick();
	}
	else
		log_error("Iteration function failed");

	return (0);
}
