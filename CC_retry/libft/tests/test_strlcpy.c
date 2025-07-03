/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strlcpy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/24 12:22:26 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/03 16:13:57 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_strlcpy(void)
{
	char	*my_src;
	char	*my_dest;
	char	*std_src;
	char	*std_dest;
	size_t	my_srclen;
	size_t	std_srclen;

	my_src = "Hello, World!";
	my_dest = malloc(sizeof(char) * 14);
	std_src = "Hello, World!";
	std_dest = malloc(sizeof(char) * 14);
	my_srclen = ft_strlcpy(my_dest, my_src, 14);
	std_srclen = ft_strlcpy(std_dest, std_src, 14);
	log_test(strcmp(std_dest, my_dest) == 0,
		"String comparison did not return 0 in exact length");
	log_test((std_srclen - my_srclen) == 0,
		"The length of src does not match in exact lenght");
	log_test(strrchr(my_dest, '\0') != NULL,
		"There is no NULL terminator in exact lenght");
	free(my_dest);
	free(std_dest);

	my_src = "Hello, World!";
	my_dest = malloc(sizeof(char) * 14);
	std_src = "Hello, World!";
	std_dest = malloc(sizeof(char) * 14);
	my_srclen = ft_strlcpy(my_dest, my_src, 10);
	std_srclen = ft_strlcpy(std_dest, std_src, 10);
	log_test(strcmp(std_dest, my_dest) == 0,
		"String comparison did not return 0 in smaller src");
	log_test((std_srclen - my_srclen) == 0,
		"The length of src does not match in smaller src");
	log_test(strrchr(my_dest, '\0') != NULL,
		"There is no NULL terminator in smaller src");
	free(my_dest);
	free(std_dest);

	my_src = "Hello, World!";
	my_dest = malloc(sizeof(char) * 14);
	std_src = "Hello, World!";
	std_dest = malloc(sizeof(char) * 14);
	my_srclen = ft_strlcpy(my_dest, my_src, 20);
	std_srclen = ft_strlcpy(std_dest, std_src, 20);
	log_test(strcmp(std_dest, my_dest) == 0,
		"String comparison did not return 0 in larger src");
	log_test((std_srclen - my_srclen) == 0,
		"The length of src does not match in larger src");
	log_test(strrchr(my_dest, '\0') != NULL,
		"There is no NULL terminator in larger src");
	free(my_dest);
	free(std_dest);

	my_src = "Hello, World!";
	memset(my_dest, 'A', 10);
	log_test(ft_strlcpy(my_dest, my_src, 0) == strlen(my_src) && my_dest[0] == 'A',
		"If the copy size is zero it does not create dest correctly");
	free(my_dest);

	my_src = "";
	my_dest = malloc(10);
	memset(my_dest, 'A', 10);
	log_test(ft_strlcpy(my_dest, my_src, 42) == 0 && !memcmp("", my_dest, 1),
		"If src is empty it does not create dest correctly");
	free(my_dest);

	my_src = "coucou";
	my_dest = malloc(10);
	memset(my_dest, 'A', 10);
	log_test(ft_strlcpy(my_dest, my_src, 2) == strlen(my_src) && my_dest[0] == 'c' && my_dest[1] == 0  && my_dest[2] == 'A',
		"If size is 2 it does not create dest correctly");
	free(my_dest);
}
