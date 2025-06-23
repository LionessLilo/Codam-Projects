/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 11:51:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/23 16:18:14 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "./test_utils.h"
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <bsd/string.h>

int	main(void)
{
	printf("\nis_alpha: ");
	test_isalpha();
	printf("\nis_isdigit: ");
	test_isdigit();
	printf("\nis_isalnum: ");
	test_isalnum();
	printf("\nis_isprint: ");
	test_isprint();
	printf("\nstrlen: ");
	test_strlen();
	printf("\nmemset: ");
	test_memset();
	printf("\nbzero: ");
	test_bzero();
	printf("\nft_memcpy: ");
	test_memcpy();
	printf("\nft_memmove: ");
	test_memmove();

// 	/* ft_memmove */
// 	printf("\nft_memmove:");
// 	char	memmove_src[] = "Hello";
// 	char	memmove_dest[] = "World";
// 	char	*ft_memmove_result = ft_memmove(memmove_dest, memmove_src, 4);
// 	char	*memmove_result = memmove(memmove_dest, memmove_src, 4);
// 	if (memcmp(ft_memmove_result, memmove_result, 5) == 0)
// 		log_tick();
// 	else
// 	{
// 		printf("ft_memset result: %s\n", ft_memmove_result);
// 		printf("memset result: %s\n", memmove_result);
// 	}

// 	/* ft_strlcpy */
// 	printf("\nft_strlcpy:");
// 	char	src1[] = "Hello, World!";
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

// 	/* ft_strlcat */
// 	printf("\nft_strlcat:");

// char strlcat_src1[] = "Hello, World!";
// char strlcat_dest1[20] = {0};
// char strlcat_src2[] = "Hello, World!";
// char strlcat_dest2[20] = {0};

// size_t ftstrlcat__result = ft_strlcat(strlcat_dest1, strlcat_src1, sizeof(strlcat_dest1));
// size_t strlcat_manual_result = strlcat(strlcat_dest2, strlcat_src2, sizeof(strlcat_dest2));

// if (ftstrlcat__result == strlcat_manual_result && strcmp(strlcat_dest1, strlcat_dest2) == 0)
// 	log_tick();
// else
// {
// 	printf("ft_strlcat result: %zu, dest: %s\n", ftstrlcat__result, strlcat_dest1);
// 	printf("strlcat result: %zu, dest: %s\n", strlcat_manual_result, strlcat_dest2);
// 	log_error("ft_strlcat does not match strlcat");
// }

// /* ft_toupper */
// printf("\033[0;37m\nft_toupper:");
// if (ft_toupper('a') == 'A')
// 	log_tick();
// else
// {
// 	log_error("Did not change 'a' to 'A' ");
// 	printf("%d", ft_toupper('a'));
// }
// if (ft_toupper(1) == 1)
// 	log_tick();
// else
// 	log_error("Changed the input (1)");

// /* ft_tolower */
// printf("\033[0;37m\nft_tolower:");
// if (ft_tolower('A') == 'a')
// 	log_tick();
// else
// {
// 	log_error("Did not change 'a' to 'A'");
// 	printf("%d\n", ft_tolower('a'));
// }
// if (ft_tolower(1) == 1)
// 	log_tick();
// else
// 	log_error("Changed the input (1)");

// /* ft_strchr */
// printf("\033[0;37m\nft_strchr:");
// char *ft_returned_ptr = ft_strchr("Hello", 'l');
// char *man_strchr = strchr("Hello", 'l');
// if (memcmp(ft_returned_ptr, man_strchr, 1) == 0)
// 	log_tick();
// else
// {
// 	log_error("Not returning the correct pointer");
// 	printf("%p", (void *)ft_returned_ptr);
// }

// /* ft_strrchr */
// printf("\033[0;37m\nft_strrchr:");
// char *ft_strrchr_returned_ptr = ft_strrchr("Hello", 'l');
// char *man_strrchr = strrchr("Hello", 'l');
// if (memcmp(ft_strrchr_returned_ptr, man_strrchr, 1) == 0)
// 	log_tick();
// else
// {
// 	log_error("Not returning the correct pointer");
// 	printf("%p", (void *)ft_strrchr_returned_ptr);
// }

// char *ft_strrchr_NULL_ptr = ft_strrchr("Hello", '\0');
// char *man_strrchr_NULL = strrchr("Hello", '\0');
// if (memcmp(ft_strrchr_NULL_ptr, man_strrchr_NULL, 1) == 0)
// 	log_tick();
// else
// {
// 	log_error("Not returning the correct pointer");
// 	printf("%p", (void *)ft_strrchr_NULL_ptr);
// }

// /* ft_strncmp */
// printf("\033[0;37m\nft_strncmp:");
// int ft_strncmp_result1 = ft_strncmp("Hello", "Help!", 4);
// int ft_strncmp_result2 = ft_strncmp("Hello", "Hello", 4);
// if (ft_strncmp_result1 == -4)
// 	log_tick();
// else
// {
// 	log_error("ft_strncmp result does not match strncmp result");
// 	printf("%d", ft_strncmp_result1);
// }
// if (ft_strncmp_result2 == 0)
// 	log_tick();
// else
// {
// 	log_error("ft_strncmp result does not match strncmp result");
// 	printf("%d", ft_strncmp_result2);
// }

// int ft_strncmp_reverse_result = ft_strncmp("Help!", "Hello", 4);
// if (ft_strncmp_reverse_result == 4)
// 	log_tick();
// else
// {
// 	log_error("ft_strncmp result does not match strncmp result");
// 	printf("%d", ft_strncmp_reverse_result);
// }

// /* ft_memchr */
// printf("\033[0;37m\nft_memchr:");
// char *ft_memchr_ptr = ft_memchr("Hello", 'l', 3);
// char *man_memchr = memchr("Hello", 'l', 3);
// if (memcmp(ft_memchr_ptr, man_memchr, 1) == 0)
// 	log_tick();
// else
// {
// 	log_error("Not returning the correct pointer");
// 	printf("%p", (void *)ft_returned_ptr);
// }

// /* ft_memcmp */
// printf("\033[0;37m\nft_memcmp:");
// int ft_memcmp_result = ft_memcmp("Hello", "Help!", 5);
// int man_memcmp = memcmp("Hello", "Help!", 5);
// if (memcmp(ft_memchr_ptr, man_memchr, 1) == 0)
// 	log_tick();
// else
// {
// 	log_error("Not returning the correct pointer");
// 	printf("%p", (void *)ft_returned_ptr);
// }

// /* ft_strnstr */
// printf("\033[0;37m\nft_strnstr:");
// const char	*ft_needlefound = ft_strnstr("Hello World", "llo", 7);
// const char	*needle_found = strnstr("Hello World", "llo", 7);
// if (strcmp(ft_needlefound, needle_found) == 0)
// 	log_tick();
// else
// 	log_error("Not correct");

// /* ft_atoi */
// printf("\033[0;37m\nft_atoi:");
// int	my_atoi = ft_atoi("-1234");
// int	std_atoi = atoi("-1234");
// if (my_atoi == std_atoi)
// 	log_tick();
// else
// {
// 	log_error("Not matching with atoi: ");
// 	printf("%d vs %d", my_atoi, std_atoi);
// }

// 	/*  End of function */
	return (printf("\n"), 0);
}
