/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 09:15:31 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/19 12:51:21 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./MLX42/include/MLX42/MLX42_Int.h"
# include "./printf/ft_printf.h"
# include "./printf/libft/libft.h"
# include <stdlib.h>
# include <aio.h>

# define WIDTH 1000
# define HEIGHT 1000

void	create_mandelbrot_image(mlx_t mandelbrot_window);

#endif