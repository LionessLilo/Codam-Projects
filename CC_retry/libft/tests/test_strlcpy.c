/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strlcpy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/24 12:22:26 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/24 13:19:37 by lilo          ########   odam.nl         */
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
}

//	char	src1[] = "Hello, World!";
// 	char	dest1[20];
// 	char	src2[] = "Hello, World!";
// 	char	dest2[20];
// 	size_t	ft_result = ft_strlcpy(dest1, src1, sizeof(dest1));
// 	size_t	manual_result = strlcpy(dest2, src2, sizeof(dest2));
// 	if (ft_result == manual_result && strcmp(dest1, dest2) == 0)
// 		log_tick();
// 	else
// 	{
// 		printf("ft_strlcpy result: %zu, dest: %s\n", ft_result, dest1);
// 		printf("strlcpy result: %zu, dest: %s\n", manual_result, dest2);
// 		log_error("ft_strlcpy does not match strlcpy");
// 	}