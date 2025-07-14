/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 14:24:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/14 14:43:41 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	error_message(char *message)
{
	write(2, "Error: ", 8);
	write(2, &message, ft_strlen(message));
	write(2, "\n", 1);
}
