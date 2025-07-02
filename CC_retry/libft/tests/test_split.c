/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_split.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 12:52:34 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/02 13:16:39 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

static void	free_list(char **list)
{
	size_t i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

void	test_split(void)
{
	char	**returned_list;

	returned_list = ft_split("Bread,milk,eggs", ',');
	log_test(strcmp(returned_list[0], "Bread") == 0
			&& strcmp(returned_list[1], "milk") == 0
			&& strcmp(returned_list[2], "eggs") == 0
			&& returned_list[3] == NULL, 
			"Did not correctly create normal list");
	free_list(returned_list);
	returned_list = NULL;

	returned_list = ft_split(",,Bread,milk,eggs,,", ',');
	log_test(strcmp(returned_list[0], "Bread") == 0
			&& strcmp(returned_list[1], "milk") == 0
			&& strcmp(returned_list[2], "eggs") == 0
			&& returned_list[3] == NULL, 
			"Did not correctly create delimeter before and after list");
	free_list(returned_list);
	returned_list = NULL;

	returned_list = ft_split(",,Bread,,,milk,eggs,,", ',');
	log_test(strcmp(returned_list[0], "Bread") == 0
			&& strcmp(returned_list[1], "milk") == 0
			&& strcmp(returned_list[2], "eggs") == 0
			&& returned_list[3] == NULL, 
			"Did not correctly create delimiter in the middle list");
	free_list(returned_list);
	returned_list = NULL;
}
