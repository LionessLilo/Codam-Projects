/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 11:51:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/07/02 17:28:08 by lilo          ########   odam.nl         */
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
	printf("\nft_atoi: ");
	test_atoi();
	printf("\nft_strdup: ");
	test_strdup();
	printf("\nft_substr: ");
	test_substr();
	printf("\nft_strjoin: ");
	test_strjoin();
	printf("\nft_itoa: ");
	test_itoa();
	printf("\nft_strtrim: ");
	test_strtrim();
	printf("\nft_strmapi: ");
	test_strmapi();
	printf("\nft_striteri: ");
	test_striteri();
	printf("\nft_split: ");
	test_split();
	printf("\nft_putchar_fd: ");
	test_putchar_fd();
	printf("\nft_putstr_fd: ");
	test_putstr_fd();
	printf("\nft_putendl_fd: ");
	test_putendl_fd();
	return (printf("\n"), 0);
}
