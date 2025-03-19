/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 09:25:30 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/19 12:49:58 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	main(void)
{
	mlx_t		*mlx_window;
	char		*set_type;

	mlx_window = mlx_init(WIDTH, HEIGHT, "fractol", true);
	set_type = "mandelbrot";
	if (ft_strncmp(set_type, "mandelbrot", 10) == 0)
		create_mandelbrot_image(*mlx_window);
	mlx_loop(mlx_window);
	mlx_terminate(mlx_window);
	return (0);
}
