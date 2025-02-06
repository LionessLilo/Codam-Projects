/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 11:51:19 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/06 15:19:38 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../printf/ft_printf.h"
# include "../printf/libft/libft.h"
# include <unistd.h>

// Error handling
void	error_and_exit(int error_code);
int		input_errors(int argc, char **argv);

#endif