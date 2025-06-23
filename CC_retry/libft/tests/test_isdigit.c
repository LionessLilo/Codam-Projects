/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_isdigit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 15:02:40 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/23 15:18:51 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_isdigit(void)
{
	int	my_isdigit;
	int	std_isdigit;

	my_isdigit = ft_isdigit('9');
	std_isdigit = isdigit('9');
	log_test(my_isdigit != 0 && std_isdigit != 0, "It should return 1");

	my_isdigit = ft_isalpha(' ');
	std_isdigit = isalpha(' ');
	log_test(my_isdigit == 0 && std_isdigit == 0, "It should return 0");
}
