/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lib_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 14:00:29 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/14 14:45:53 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length])
		length++;
	return (length);
}
