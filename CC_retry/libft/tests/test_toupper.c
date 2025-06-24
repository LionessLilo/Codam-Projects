/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_toupper.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/24 14:22:41 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/24 14:32:42 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_toupper(void)
{
	char	my_toupper;
	char	std_toupper;

	my_toupper = ft_toupper('a');
	std_toupper = toupper('a');
	log_test((std_toupper - my_toupper) == 0,
		"The returned characters do not match");

	my_toupper = ft_toupper('Z');
	std_toupper = toupper('Z');
	log_test((std_toupper - my_toupper) == 0,
		"The returned characters do not match");

	my_toupper = ft_toupper(' ');
	std_toupper = toupper(' ');
	log_test((std_toupper - my_toupper) == 0,
		"The returned characters do not match");
}
