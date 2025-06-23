/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_isprint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 15:22:50 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/23 15:24:52 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_isprint(void)
{
	int	my_isprint;
	int	std_isprint;

	my_isprint = ft_isprint('~');
	std_isprint = isprint('~');
	log_test(my_isprint != 0 && std_isprint != 0, "It should return 1");

	my_isprint = ft_isalpha('\t');
	std_isprint = isalpha('\t');
	log_test(my_isprint == 0 && std_isprint == 0, "It should return 0");
}
