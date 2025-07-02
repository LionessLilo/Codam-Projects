/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strtrim.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/30 13:55:23 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/30 15:15:19 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_strtrim(void)
{
	char	*trimmed_str;

	trimmed_str = malloc(sizeof(char) * 6);
	if (!trimmed_str)
		exit(-1);
	trimmed_str = ft_strtrim(" H ello \n\n", " \n");
	if (!trimmed_str)
	{
		printf("trimmed str returned NULL");
		exit(-1);
	}
	log_test(strcmp(trimmed_str, "H ello") == 0, "Did not trim properly");
	free(trimmed_str);

	trimmed_str = malloc(sizeof(char) * 13);
	if (!trimmed_str)
		exit(-1);
	trimmed_str = ft_strtrim(" H ello World \n\n", " \n");
	if (!trimmed_str)
	{
		printf("trimmed str returned NULL");
		exit(-1);
	}
	log_test(strcmp(trimmed_str, "H ello World") == 0, "Did not trim properly");
	free(trimmed_str);

	trimmed_str = malloc(sizeof(char) * 1);
	if (!trimmed_str)
		exit(-1);
	trimmed_str = ft_strtrim(" \n\n", " \n");
	if (!trimmed_str)
	{
		printf("trimmed str returned NULL");
		exit(-1);
	}
	log_test(strcmp(trimmed_str, "") == 0, "Did not trim properly");
	free(trimmed_str);
}
