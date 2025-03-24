/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coordinate_functions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/21 18:04:35 by lilo          #+#    #+#                 */
/*   Updated: 2025/03/21 18:21:24 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	log_tick(void)
{
	printf("\033[0;32m ✔ \033[0;37m \n");
}

int	main(void)
{
	t_coordinates	coordinates;
	bool			is_inside_manedelbrot;

	coordinates.x_coord = 1;
	coordinates.y_coord = 2;
	is_inside_manedelbrot = inside_mandelbrot(coordinates);
	if (is_inside_manedelbrot == true)
	{
		printf("Is inside mandelbrot: ");
	}
	return (0);
}