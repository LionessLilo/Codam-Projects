/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_memset.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 15:34:43 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/23 16:44:23 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_memset(void)
{
	void	*my_memset;
	void	*std_memset;

	my_memset = malloc(sizeof(void *) * 10);
	std_memset = malloc(sizeof(void *) * 10);
	my_memset = ft_memset(my_memset, 'H', 10);
	std_memset = memset(my_memset, 'H', 10);
	log_test(memcmp(my_memset, std_memset, 10) == 0,
		"Memory comparison is greater than zero");
}
