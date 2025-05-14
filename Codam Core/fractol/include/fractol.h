/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 15:00:37 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/14 17:14:46 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define REAL_MAX 1.0
# define REAL_MIN -2.0
# define IMAG_MAX 1.5
# define IMAG_MIN -1.5
# define MAX_ITER 1000

typedef struct s_window
{
	void	*mlx;
	void	*image;
	int		image_instance;
}			t_window;

typedef struct s_pixels
{
	int	x;
	int	y;
}		t_pixels;

typedef struct s_complex_coord
{
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
}			t_complex_coord;

typedef struct s_zoom
{
	t_window	*window;
	double		zoom;
}				t_zoom;

t_complex_coord	pixels_to_complex(t_pixels pixels);
int				mandelbrot(t_pixels pixels);
void			place_pixels(int iterations, t_window window, t_pixels pixels);
void			display_mandelbrot(void);
void			scroll_function(mouse_key_t mlx_scroll_hook);

#endif