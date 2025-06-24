/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strlcat.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/24 13:22:32 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/24 14:00:09 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "./test_utils.h"

void	test_strlcat(void)
{
	char	*my_src;
	char	*my_dest;
	char	*std_src;
	char	*std_dest;
	size_t	my_srclen;
	size_t	std_srclen;

	my_src = "World";
	my_dest = malloc(sizeof(char) * 13);
	strlcpy(my_dest, "Hello ", 7);
	std_src = "World";
	std_dest = malloc(sizeof(char) * 13);
	strlcpy(std_dest, "Hello ", 7);
	my_srclen = ft_strlcat(my_dest, my_src, 13);
	std_srclen = ft_strlcat(std_dest, std_src, 13);
	log_test(strcmp(std_dest, my_dest) == 0,
		"String comparison did not return 0 in exact length");
	log_test((std_srclen - my_srclen) == 0,
		"The length it tried to create does not match in exact lenght");
	log_test(strrchr(my_dest, '\0') != NULL,
		"There is no NULL terminator in exact lenght");
	free(my_dest);
	free(std_dest);

	my_src = "World";
	my_dest = malloc(sizeof(char) * 10);
	strlcpy(my_dest, "Hello ", 7);
	std_src = "World";
	std_dest = malloc(sizeof(char) * 10);
	strlcpy(std_dest, "Hello ", 7);
	my_srclen = ft_strlcat(my_dest, my_src, 13);
	std_srclen = ft_strlcat(std_dest, std_src, 13);
	log_test(memcmp(std_dest, my_dest, sizeof(char) * 10) == 0,
		"String comparison did not return 0 smaller");
	log_test((std_srclen - my_srclen) == 0,
		"The length it tried to create does not match in smaller dest");
	log_test(strrchr(my_dest, '\0') != NULL,
		"There is no NULL terminator in smaller dest");
	free(my_dest);
	free(std_dest);

	my_src = "World";
	my_dest = malloc(sizeof(char) * 20);
	strlcpy(my_dest, "Hello ", 7);
	std_src = "World";
	std_dest = malloc(sizeof(char) * 20);
	strlcpy(std_dest, "Hello ", 7);
	my_srclen = ft_strlcat(my_dest, my_src, 20);
	std_srclen = ft_strlcat(std_dest, std_src, 20);
	log_test(memcmp(std_dest, my_dest, sizeof(char) * 20) == 0,
		"Memory comparison did not return 0 in exact length");
	log_test((std_srclen - my_srclen) == 0,
		"The length it tried to create does not match in exact lenght");
	log_test(strrchr(my_dest, '\0') != NULL,
		"There is no NULL terminator in exact lenght");
	free(my_dest);
	free(std_dest);
}
