/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/20 13:54:55 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/20 16:44:06 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Allocates memory and fills it with zeros. Accommodates for
	integer overflow. 
*/

void	*calloc(size_t nbrof_items, size_t size_item)
{
	void	*memory;

	if (size_item != 0 && nbrof_items > (((size_t) - 1) / size_item))
		return (NULL);
	memory = malloc(nbrof_items * size_item);
	if (!memory)
		return (NULL);
	ft_bzero(memory, (nbrof_items * size_item));
	return (memory);
}
