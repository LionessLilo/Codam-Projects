/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_striteri.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/30 17:40:54 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/01 09:59:36 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

static void	map_func(unsigned int i, char *c)
{
	*c = *c + i;
}

void	test_striteri(void)
{
	char	*str1;

	str1 = strdup("hello");
	ft_striteri(str1, map_func);
	log_test(strcmp(str1, "hfnos") == 0, "Did not apply function properly");
	free(str1);

	str1 = strdup("");
	ft_striteri(str1, map_func);
	log_test(strcmp(str1, "") == 0, "Did not apply function properly");
	free(str1);

	str1 = NULL;
	ft_striteri(str1, map_func);
	if (!str1)
		log_tick();
	else
		log_error("Did not return NULL");
}
