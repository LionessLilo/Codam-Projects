/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_substr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/26 14:47:10 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/26 15:08:47 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_substr(void)
{
	char	*substr_return;

	substr_return = ft_substr("Hello for Lilo", 6, 8);
	log_test(strcmp(substr_return, "for Lilo") == 0,
		"Did not create the substring correctly");
	free(substr_return);

	substr_return = ft_substr("Hello for Lilo", 16, 4);
	log_test(strcmp(substr_return, "") == 0,
		"Did not create the substring correctly for start greater than len");
	free(substr_return);

	substr_return = ft_substr("Hello for Lilo", 11, 6);
	log_test(strcmp(substr_return, "ilo") == 0,
		"Did not create the substring correctly for substr more than len");
	free(substr_return);
}
