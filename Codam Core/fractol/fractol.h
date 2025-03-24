/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 09:15:31 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/21 18:00:28 by lilo          ########   odam.nl         */
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
# include <stdbool.h>

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 3

typedef struct s_coordinates
{
	double	x_coord;
	double	y_coord;

}			t_coordinates;

/*Mandelbrot*/
void	create_mandelbrot_image(mlx_t mandelbrot_window);
int		iterations(t_coordinates s_coordinates);

/*Utils*/
bool	inside_mandelbrot(t_coordinates coordinates);

#endif