/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_memmove.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 16:18:33 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/24 12:38:57 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_memmove(void)
{
	char	*memmove_src;
	char	*memmove_dest;
	char	*ft_memmove_result;
	char	*memmove_result;

	memmove_src = malloc(sizeof(char) * 11);
	strcpy(memmove_src, "Hello");
	memmove_dest = malloc(sizeof(char) * 10);
	strcpy(memmove_dest, "World");
	ft_memmove_result = ft_memmove(memmove_dest, memmove_src, 4);
	memmove_result = memmove(memmove_dest, memmove_src, 4);
	log_test(memcmp(ft_memmove_result, memmove_result, 10) == 0,
		"Memory move was not successful");
	free(memmove_src);

	memmove_src = malloc(sizeof(char) * 11);
	strcpy(memmove_src, "Hello");
	memmove_dest = malloc(sizeof(char) * 10);
	strcpy(memmove_dest, "World");
	ft_memmove_result = ft_memmove(memmove_dest, memmove_src, 0);
	memmove_result = memmove(memmove_dest, memmove_src, 0);
	log_test(memcmp(ft_memmove_result, memmove_result, 10) == 0,
		"Memory move was not successful");

	free(memmove_src);
	memmove_src = malloc(sizeof(char) * 20);
	strcpy(memmove_src, "Hello, World!");
	memmove_dest = memmove_src + 7;
	ft_memmove_result = ft_memmove(memmove_dest, memmove_src, 6);
	memmove_result = memmove(memmove_dest, memmove_src, 6);
	log_test(memcmp(ft_memmove_result, memmove_result, 13) == 0,
		"Memory move for overlapping regions was not successful");

	free(memmove_src);
}
