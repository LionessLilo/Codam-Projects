/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_isalnum.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 15:07:07 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/23 15:18:37 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_isalnum(void)
{
	int	my_isalnum;
	int	std_isalnum;

	my_isalnum = ft_isalnum('9');
	std_isalnum = isalnum('9');
	log_test(my_isalnum != 0 && std_isalnum != 0, "It should return 1");

	my_isalnum = ft_isalnum('a');
	std_isalnum = isalnum('a');
	log_test(my_isalnum != 0 && std_isalnum != 0, "It should return 1");

	my_isalnum = ft_isalnum(' ');
	std_isalnum = isalnum(' ');
	log_test(my_isalnum == 0 && std_isalnum == 0, "It should return 0");
}
