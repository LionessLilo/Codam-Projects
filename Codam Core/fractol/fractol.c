/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 09:25:30 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/13 16:46:12 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	main(void)
{
	mlx_t		*mlx_window;
	mlx_image_t	*canvas;
	char		*fractol_type;
	double		width_with_border;
	double		height_with_border;

	width_with_border = WIDTH * 0.1;
	height_with_border = HEIGHT * 0.1;
	mlx_window = mlx_init(WIDTH, HEIGHT, "fractol", true);
	canvas = mlx_new_image(mlx_window, WIDTH, HEIGHT);
	if (fractol_type == 'Mandelbrot')
		create_mandelbrot_image(width_with_border, height_with_border, canvas);
	mlx_image_to_window(mlx_window, canvas, (WIDTH / 2), (HEIGHT / 2));
	mlx_loop(mlx_window);
	mlx_terminate(mlx_window);
	return (0);
}
