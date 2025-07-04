/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_bzero.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 15:50:04 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/23 15:56:35 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_bzero(void)
{
	void	*my_bzero;
	void	*std_bzero;

	my_bzero = malloc(sizeof(void *) * 10);
	std_bzero = malloc(sizeof(void *) * 10);
	memset(my_bzero, 'O', 10);
	memset(std_bzero, 'O', 10);
	ft_bzero(my_bzero, 10);
	bzero(std_bzero, 10);
	log_test(memcmp(my_bzero, std_bzero, 10) == 0,
		"Memory comparison is greater than zero");
}
