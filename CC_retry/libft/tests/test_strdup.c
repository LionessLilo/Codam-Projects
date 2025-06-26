/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strdup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/26 12:27:22 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/26 14:41:44 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "./test_utils.h"

void	test_strdup(void)
{
	char	*string;
	char	*my_duplicated_str;
	char	*std_duplicated_str;

	string = "Hello Lilo";
	my_duplicated_str = ft_strdup(string);
	std_duplicated_str = strdup(string);
	log_test(memcmp(std_duplicated_str, my_duplicated_str,
			(ft_strlen(string) + 1)) == 0,
		"Memory comparison returns a difference");
	free(my_duplicated_str);
	free(std_duplicated_str);

	string = "";
	my_duplicated_str = ft_strdup(string);
	std_duplicated_str = strdup(string);
	log_test(memcmp(std_duplicated_str, my_duplicated_str,
			(ft_strlen(string) + 1)) == 0,
		"Memory comparison returns a difference in an ampty string");
	free(my_duplicated_str);
	free(std_duplicated_str);
}
