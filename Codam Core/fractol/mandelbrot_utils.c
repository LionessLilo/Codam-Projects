/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 17:45:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/21 13:10:58 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	init_data(t_data *data)
{
	data->window_width = 800;
	data->window_height = 600;
	data->real_max = 1.0;
	data->real_min = -2.0;
	data->imag_max = 1.5;
	data->imag_min = -1.5;
	data->max_iter = 150;
}