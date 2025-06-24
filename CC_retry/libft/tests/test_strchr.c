/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strchr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/24 14:39:02 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/24 14:51:18 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "./test_utils.h"

void	test_strchr(void)
{
	char	*my_ptr_returned;
	char	*std_ptr_returned;

	my_ptr_returned = ft_strchr("Hello World", 'l');
	std_ptr_returned = strchr("Hello World", 'l');
	log_test(memcmp(std_ptr_returned, my_ptr_returned,
			sizeof(char) * strlen(std_ptr_returned)) == 0,
		"The returned pointers do not match");

	my_ptr_returned = ft_strchr("Hello World", '\0');
	std_ptr_returned = strchr("Hello World", '\0');
	log_test(memcmp(std_ptr_returned, my_ptr_returned,
			sizeof(char) * strlen(std_ptr_returned)) == 0,
		"The returned pointers for NULL do not match");
}
