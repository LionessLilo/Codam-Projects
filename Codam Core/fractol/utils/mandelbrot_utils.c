/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/21 16:50:29 by lilo          #+#    #+#                 */
/*   Updated: 2025/03/24 18:00:25 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

bool	inside_mandelbrot(t_coordinates coordinates)
{
	double	compare_value;

	compare_value = (coordinates.x_coord * coordinates.x_coord)
		+ (coordinates.y_coord * coordinates.y_coord);
	if (compare_value < 4)
		return (true);
	else
		return (false);
}

void	find_new_coordinates(t_coordinates *coordinates)
{
	double	temp_coord_1;
	double	temp_coord_2;

	temp_coord_1 = (coordinates->x_coord * coordinates->x_coord)
		- (coordinates->y_coord * coordinates->y_coord);
	temp_coord_2 = 2 * (coordinates->x_coord * coordinates->y_coord);
	coordinates->x_coord = temp_coord_1 + coordinates->x_coord;
	coordinates->y_coord = temp_coord_2 + coordinates->y_coord;
}
