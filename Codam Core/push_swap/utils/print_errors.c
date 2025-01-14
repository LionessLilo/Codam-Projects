/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/14 14:06:41 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/14 14:09:35 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

void	error_malloc(char	*variable)
{
	ft_printf("could not malloc %s", variable);
}
