/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strmapi.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/30 17:00:51 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/30 17:27:03 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


static char	map_func(unsigned int i, char c)
{
	return (c + i);
}

void	test_strmapi(void)
{
	char	*result;

	result = ft_strmapi("hello", map_func);
	if (!result)
	{
		printf("result returned NULL");
		exit(-1);
	}
	log_test(strcmp(result, "hfnos") == 0, "Did not map properly");
	free(result);
}
