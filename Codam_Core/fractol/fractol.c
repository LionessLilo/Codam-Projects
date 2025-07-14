/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 11:43:34 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/26 16:37:47 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

int	main(void)
{
	t_data	data;

	init_data(&data);
	display_mandelbrot(data);
	return (0);
}
