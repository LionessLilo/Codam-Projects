/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 09:15:31 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/19 16:48:50 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./MLX42/include/MLX42/MLX42_Int.h"
# include "./printf/ft_printf.h"
# include "./printf/libft/libft.h"
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 1000

typedef struct s_complex_nbr
{
	double	real;
	double	imaginary;

}			t_complex_nbr;

typedef struct s_coordinates
{
	double	x;
	double	y;

}			t_coordinates;

/*Mandelbrot*/
void	create_mandelbrot_image(mlx_t mandelbrot_window);
int		mandelbrot_equation(t_coordinates coordinates);

#endif