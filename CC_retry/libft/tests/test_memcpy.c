/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_memcpy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 15:59:20 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/23 17:03:40 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_memcpy(void)
{
	void	*my_src_memcpy;
	void	*my_dest_memcpy;
	void	*std_src_memcpy;
	void	*std_dest_memcpy;

	my_src_memcpy = "Hello";
	my_dest_memcpy = malloc(sizeof(void *) * 10);
	std_src_memcpy = "Hello";
	std_dest_memcpy = malloc(sizeof(void *) * 10);
	ft_memcpy(my_dest_memcpy, my_src_memcpy, 10);
	memcpy(std_dest_memcpy, std_src_memcpy, 10);
	log_test(memcmp(my_dest_memcpy, std_dest_memcpy, 10) == 0,
		"Memory comparison is greater than zero");

	my_src_memcpy = "Hello World this is Lilo";
	std_src_memcpy = "Hello World this is Lilo";
	ft_memcpy(my_dest_memcpy, my_src_memcpy, 10);
	memcpy(std_dest_memcpy, std_src_memcpy, 10);
	log_test(memcmp(my_dest_memcpy, std_dest_memcpy, 10) == 0,
		"Memory comparison is greater than zero");

	free(my_dest_memcpy);
	free(std_dest_memcpy);
}
