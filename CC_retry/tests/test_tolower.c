/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_tolower.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/24 14:35:59 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/24 14:37:31 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_tolower(void)
{
	char	my_tolower;
	char	std_tolower;

	my_tolower = ft_tolower('a');
	std_tolower = tolower('a');
	log_test((std_tolower - my_tolower) == 0,
		"The returned characters do not match");

	my_tolower = ft_tolower('Z');
	std_tolower = tolower('Z');
	log_test((std_tolower - my_tolower) == 0,
		"The returned characters do not match");

	my_tolower = ft_tolower(' ');
	std_tolower = tolower(' ');
	log_test((std_tolower - my_tolower) == 0,
		"The returned characters do not match");
}
