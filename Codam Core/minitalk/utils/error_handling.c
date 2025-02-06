/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 15:03:28 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/06 15:05:51 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	error_and_exit(int error_code)
{
	ft_putendl_fd("Error\n", 2);
	exit (error_code);
}
