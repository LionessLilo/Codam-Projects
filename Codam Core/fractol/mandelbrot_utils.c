/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 17:45:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/16 12:20:24 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

/* Translates pixel to complex number. Gives me the value of c at pixel (x,y) */
t_complex_coord	pixels_to_complex(t_pixels pixels)
{
	t_complex_coord	coords;

	coords.c_real = REAL_MIN + pixels.x * (REAL_MAX - REAL_MIN) / WINDOW_WIDTH;
	coords.c_imag = IMAG_MAX - pixels.y * (IMAG_MAX - IMAG_MIN) / WINDOW_HEIGHT;
	return (coords);
}
void	zoom_in(void)
{

}
