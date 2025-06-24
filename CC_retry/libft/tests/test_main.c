/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 11:51:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/24 16:34:18 by lilo          ########   odam.nl         */
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
	printf("\nft_strlcpy: ");
	test_strlcpy();
	printf("\nft_strlcat: ");
	test_strlcat();
	printf("\nft_toupper: ");
	test_toupper();
	printf("\nft_tolower: ");
	test_tolower();
	printf("\nft_strchr: ");
	test_strchr();
	printf("\nft_strrchr: ");
	test_strrchr();
	printf("\nft_strncmp: ");
	test_strncmp();
	printf("\nft_memchr: ");
	test_memchr();
	printf("\nft_memcmp: ");
	test_memcmp();

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
