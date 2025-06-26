/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strjoin.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/26 15:23:42 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/26 17:03:44 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_strjoin(void)
{
	char	*joined_str;

	joined_str = ft_strjoin("Hello ", "World");
	log_test(memcmp((joined_str - 11), "Hello World", 11) == 0,
		"The strings did not join correctly");
	log_test(strrchr(joined_str, '\0') != NULL,
		"There is no NULL terminator");

	joined_str = ft_strjoin("", "");
	log_test(memcmp(joined_str - 11, "", 1) == 0,
		"If strings are empty it did not return an empty string");
	log_test(strrchr(joined_str, '\0') != NULL,
		"There is no NULL terminator");

	joined_str = ft_strjoin("Hello", "");
	log_test(memcmp(joined_str - 5, "Hello", 5) == 0,
		"It did not print only the first string");
	log_test(strrchr(joined_str, '\0') != NULL,
		"There is no NULL terminator");

	joined_str = ft_strjoin("", "World");
	log_test(memcmp(joined_str - 5, "World", 5) == 0,
		"It did not print only the first string");
	log_test(strrchr(joined_str, '\0') != NULL,
		"There is no NULL terminator");
}
