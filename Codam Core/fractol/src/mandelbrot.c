/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 15:55:33 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/19 12:50:39 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	create_mandelbrot_image(mlx_t mandelbrot_window)
{
	mlx_image_t	*img;

	img = mlx_new_image(&mandelbrot_window, WIDTH, HEIGHT);
	int	y = 1000 * 0.1;
	while (y < (1000 * 0.9))
	{
		int x = 1000 * 0.1;
		while (x < (1000 * 0.9))
		{
			mlx_put_pixel(img, x, y, (rand() % 0x1000000));
			x++;
		}
		y++;
	}
	mlx_image_to_window(&mandelbrot_window, img, 0, 0);
}
