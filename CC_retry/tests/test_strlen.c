/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 15:29:41 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/23 15:33:08 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_strlen(void)
{
	int	my_strlen;
	int	std_strlen;

	my_strlen = ft_strlen("Lilo");
	std_strlen = strlen("Lilo");
	log_test((my_strlen - std_strlen) == 0, "The lengths son't match");

	my_strlen = ft_strlen("Liloisamazing ");
	std_strlen = strlen("Liloisamazing ");
	log_test((my_strlen - std_strlen) == 0, "The lengths son't match");
}
