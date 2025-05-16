/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 16:33:09 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/16 14:51:04 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"


void	mandelbrot_scroll(double x_scroll, double y_scroll, void *own_param);
void	display_mandelbrot(void);
void	place_pixels(int iterations, t_window window, t_pixels pixels);

/* 
	Takes the complex numbers converted from the pixel coordinates,
	runs it through the mandelbrot equation and returns 
	the number of iterations
*/
int	mandelbrot(t_pixels pixels)
{
	t_complex_coord	coords;
	int				iterations;
	double			temp;

	iterations = 0;
	coords = pixels_to_complex(pixels);
	coords.z_real = 0;
	coords.z_imag = 0;
	while (coords.z_real * coords.z_real + coords.z_imag * coords.z_imag <= 4
		&& iterations < MAX_ITER)
	{
		temp = coords.z_real * coords.z_real
			- coords.z_imag * coords.z_imag + coords.c_real;
		coords.z_imag = 2 * coords.z_real * coords.z_imag + coords.c_imag;
		coords.z_real = temp;
		iterations++;
	}
	return (iterations);
}

void	place_pixels(int iterations, t_window window, t_pixels pixels)
{
	uint32_t	color;

	if (iterations == MAX_ITER)
		color = 0x272643FF;
	else if (iterations >= MAX_ITER / 2)
		color = 0xe3f6f5FF;
	else if (iterations >= MAX_ITER / 4)
		color = 0xbae8e8FF;
	else if (iterations >= MAX_ITER / 16)
		color = 0x2c698dFF;
	else
		color = 0x8d2c66FF;
	mlx_put_pixel(window.image, pixels.x, pixels.y, color);
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
	while (pixels.y < WINDOW_HEIGHT && pixels.y < (int)((mlx_image_t *)window.image)->height)
	{
		pixels.x = 0;
		while (pixels.x < WINDOW_WIDTH && pixels.x < (int)((mlx_image_t *)window.image)->width)
		{
			iterations = mandelbrot(pixels);
			place_pixels(iterations, window, pixels);
			pixels.x++;
		}
		pixels.y++;
	}
	window.image_instance = mlx_image_to_window(window.mlx, window.image, 0, 0);
	mlx_scroll_hook(zoom.window->mlx, (void *)mandelbrot_scroll, &zoom);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
}

void	mandelbrot_scroll(double x_scroll, double y_scroll, void *own_param)
{
	(void)x_scroll;
	(void)own_param;
	if (y_scroll > 0)
		zoom_out();
	else if (y_scroll < 0)
		zoom_in();
}
