/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/21 16:50:29 by lilo          #+#    #+#                 */
/*   Updated: 2025/03/21 18:42:50 by lilo          ########   odam.nl         */
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

find_new_coordinates(t_coordinates s_coordinates)
{
	double			temp_coord_1;
	double			temp_coord_2;

	temp_coord_1 = (s_coordinates.x_coord * s_coordinates.x_coord)
		- (s_coordinates.y_coord * s_coordinates.y_coord);
	temp_coord_2 = 2 * (s_coordinates.x_coord * s_coordinates.y_coord);
	s_coordinates.x_coord = temp_coord_1 + s_coordinates.x_coord;
	s_coordinates.y_coord = temp_coord_2 + s_coordinates.y_coord;
}
