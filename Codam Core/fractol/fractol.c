/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 11:43:34 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/14 17:26:11 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	display_mandelbrot(void);

int	main(void)
{
	//To do: Handle input
	display_mandelbrot();
	return (0);
}

void	display_mandelbrot(void)
{
	t_window	window;
	t_pixels	pixels;
	t_zoom		zoom;
	int			iterations;

	window.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "fractol", false);
	window.image = mlx_new_image(window.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	pixels.y = 0;
	while (pixels.y < WINDOW_HEIGHT)
	{
		pixels.x = 0;
		while (pixels.x < WINDOW_WIDTH)
		{
			iterations = mandelbrot(pixels);
			place_pixels(iterations, window, pixels);
			pixels.x++;
		}
		pixels.y++;
	}
	window.image_instance = mlx_image_to_window(window.mlx, window.image, 0, 0);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
}
