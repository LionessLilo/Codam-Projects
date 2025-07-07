/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_isalpha.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 12:15:58 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/03 13:31:20 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_isalpha(void)
{
	int	my_isalpha;
	int	std_isalpha;

	my_isalpha = ft_isalpha('a');
	std_isalpha = isalpha('a');
	log_test(my_isalpha != 0 && std_isalpha != 0, "It should return 1");

	my_isalpha = ft_isalpha('1');
	std_isalpha = isalpha('1');
	log_test(my_isalpha == 0 && std_isalpha == 0, "It should return 0");
}
