/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 11:51:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/20 13:40:40 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <bsd/string.h>

static void	log_tick(void)
{
	printf("\033[0;32m ✔\033[0;37m");
}

static void	log_error(char *message)
{
	printf("\033[0;31m%s\n\n\033[0;37m", message);
}

int	main(void)
{
	/* ft_isalpha */
	printf("\033[0;37mft_isalpha:");
	if (ft_isalpha('A') == 1)
		log_tick();
	else
		log_error("Says A is not alpha");
	if (ft_isalpha(1) == 0)
		log_tick();
	else
		log_error("Says number is alpha");

	/* ft_isdigit */
	printf("\nft_isdigit:");
	if (ft_isdigit('1') == 1)
		log_tick();
	else
		log_error("Says '1' is not a digit");
	if (ft_isdigit(2) == 0)
		log_tick();
	else
		log_error("Says an integer is a digit");
	
	/* ft_ft_isalnum */
	printf("\nft_ft_isalnum");
	if (ft_isalnum('A') == 1)
		log_tick();
	else
		log_error("Thinks 'A' is not alnum");
	if (ft_isalnum('6') == 1)
		log_tick();
	else
		log_error("Thinks '6' is not alnum");
	if (ft_isalnum('$') == 0)
		log_tick();
	else
		log_error("Thinks $ is alnum");

	/* ft_isprint */
	printf("\nft_isprint:");
	if (ft_isprint('\n') == 0)
		log_tick();
	else
		log_error("Thinks new line is printable");
	if (ft_isprint('~') == 1)
		log_tick();
	else
		log_error("Does not think that '~' is not printable");
	
	/* ft_strlen */
	printf("\nft_strlen:");
	if (ft_strlen("Hello") == 5)
		log_tick();
	else
		log_error("Length is incorrect");
	
	/* ft_memset */
	printf("\nft_memset:");
	char	memset_str1[] = "Hello";
	char	memset_str2[] = "Hello";
	if (memcmp(ft_memset(memset_str1, 'f', 4), memset(memset_str2, 'f', 4), 5) == 0)
		log_tick();
	else
	{
		printf("ft_memset result: %s\n", memset_str1);
		printf("memset result: %s\n", memset_str2);
	}

	/* ft_bzero */
	printf("\nft_bzero:");
	char	bzero_str1[] = "Hello";
	char	bzero_str2[] = "Hello";
	ft_bzero(memset_str1, 4);
	bzero(memset_str2, 4);
	if (memcmp(memset_str1, memset_str2, 5) == 0)
		log_tick();
	else
	{
		printf("ft_memset result: %s\n", memset_str1);
		printf("memset result: %s\n", memset_str2);
	}

	/* ft_memcpy */
	printf("\nft_memcpy:");
	char	memcpy_src[] = "Hello";
	char	memcpy_dest[] = "World";
	char	*ftmemcpy_result = ft_memcpy(memcpy_dest, memcpy_src, 4);
	char	*memcpy_result = memcpy(memcpy_dest, memcpy_src, 4);
	if (memcmp(ftmemcpy_result, memcpy_result, 5) == 0)
		log_tick();
	else
	{
		printf("ft_memset result: %s\n", ftmemcpy_result);
		printf("memset result: %s\n", memcpy_result);
	}

	/* ft_memmove */
	printf("\nft_memmove:");
	char	memmove_src[] = "Hello";
	char	memmove_dest[] = "World";
	char	*ft_memmove_result = ft_memmove(memmove_dest, memmove_src, 4);
	char	*memmove_result = memmove(memmove_dest, memmove_src, 4);
	if (memcmp(ft_memmove_result, memmove_result, 5) == 0)
		log_tick();
	else
	{
		printf("ft_memset result: %s\n", ft_memmove_result);
		printf("memset result: %s\n", memmove_result);
	}

	/* ft_strlcpy */
	printf("\nft_strlcpy:");
	char	src1[] = "Hello, World!";
	char	dest1[20];
	char	src2[] = "Hello, World!";
	char	dest2[20];
	size_t	ft_result = ft_strlcpy(dest1, src1, sizeof(dest1));
	size_t	manual_result = strlcpy(dest2, src2, sizeof(dest2));
	if (ft_result == manual_result && strcmp(dest1, dest2) == 0)
		log_tick();
	else
	{
		printf("ft_strlcpy result: %zu, dest: %s\n", ft_result, dest1);
		printf("strlcpy result: %zu, dest: %s\n", manual_result, dest2);
		log_error("ft_strlcpy does not match strlcpy");
	}

	/* ft_strlcat */
	printf("\nft_strlcat:");

char strlcat_src1[] = "Hello, World!";
char strlcat_dest1[20] = {0};
char strlcat_src2[] = "Hello, World!";
char strlcat_dest2[20] = {0};

size_t ftstrlcat__result = ft_strlcat(strlcat_dest1, strlcat_src1, sizeof(strlcat_dest1));
size_t strlcat_manual_result = strlcat(strlcat_dest2, strlcat_src2, sizeof(strlcat_dest2));

if (ftstrlcat__result == strlcat_manual_result && strcmp(strlcat_dest1, strlcat_dest2) == 0)
	log_tick();
else
{
	printf("ft_strlcat result: %zu, dest: %s\n", ftstrlcat__result, strlcat_dest1);
	printf("strlcat result: %zu, dest: %s\n", strlcat_manual_result, strlcat_dest2);
	log_error("ft_strlcat does not match strlcat");
}

/* ft_toupper */
printf("\033[0;37m\nft_toupper:");
if (ft_toupper('a') == 'A')
	log_tick();
else
{
	log_error("Did not change 'a' to 'A' ");
	printf("%d", ft_toupper('a'));
}
if (ft_toupper(1) == 1)
	log_tick();
else
	log_error("Changed the input (1)");

/* ft_tolower */
printf("\033[0;37m\nft_tolower:");
if (ft_tolower('A') == 'a')
	log_tick();
else
{
	log_error("Did not change 'a' to 'A'");
	printf("%d\n", ft_tolower('a'));
}
if (ft_tolower(1) == 1)
	log_tick();
else
	log_error("Changed the input (1)");

/* ft_strchr */
printf("\033[0;37m\nft_strchr:");
char *ft_returned_ptr = ft_strchr("Hello", 'l');
char *man_strchr = strchr("Hello", 'l');
if (memcmp(ft_returned_ptr, man_strchr, 1) == 0)
	log_tick();
else
{
	log_error("Not returning the correct pointer");
	printf("%p", (void *)ft_returned_ptr);
}

/* ft_strrchr */
printf("\033[0;37m\nft_strrchr:");
char *ft_strrchr_returned_ptr = ft_strrchr("Hello", 'l');
char *man_strrchr = strrchr("Hello", 'l');
if (memcmp(ft_strrchr_returned_ptr, man_strrchr, 1) == 0)
	log_tick();
else
{
	log_error("Not returning the correct pointer");
	printf("%p", (void *)ft_strrchr_returned_ptr);
}

char *ft_strrchr_NULL_ptr = ft_strrchr("Hello", '\0');
char *man_strrchr_NULL = strrchr("Hello", '\0');
if (memcmp(ft_strrchr_NULL_ptr, man_strrchr_NULL, 1) == 0)
	log_tick();
else
{
	log_error("Not returning the correct pointer");
	printf("%p", (void *)ft_strrchr_NULL_ptr);
}

/* ft_strncmp */
printf("\033[0;37m\nft_strncmp:");
int ft_strncmp_result1 = ft_strncmp("Hello", "Help!", 4);
int ft_strncmp_result2 = ft_strncmp("Hello", "Hello", 4);
if (ft_strncmp_result1 == -4)
	log_tick();
else
{
	log_error("ft_strncmp result does not match strncmp result");
	printf("%d", ft_strncmp_result1);
}
if (ft_strncmp_result2 == 0)
	log_tick();
else
{
	log_error("ft_strncmp result does not match strncmp result");
	printf("%d", ft_strncmp_result2);
}

int ft_strncmp_reverse_result = ft_strncmp("Help!", "Hello", 4);
if (ft_strncmp_reverse_result == 4)
	log_tick();
else
{
	log_error("ft_strncmp result does not match strncmp result");
	printf("%d", ft_strncmp_reverse_result);
}

/* ft_memchr */
printf("\033[0;37m\nft_memchr:");
char *ft_memchr_ptr = ft_memchr("Hello", 'l', 3);
char *man_memchr = memchr("Hello", 'l', 3);
if (memcmp(ft_memchr_ptr, man_memchr, 1) == 0)
	log_tick();
else
{
	log_error("Not returning the correct pointer");
	printf("%p", (void *)ft_returned_ptr);
}

/* ft_memcmp */
printf("\033[0;37m\nft_memcmp:");
int ft_memcmp_result = ft_memcmp("Hello", "Help!", 5);
int man_memcmp = memcmp("Hello", "Help!", 5);
if (memcmp(ft_memchr_ptr, man_memchr, 1) == 0)
	log_tick();
else
{
	log_error("Not returning the correct pointer");
	printf("%p", (void *)ft_returned_ptr);
}

/* ft_strnstr */
printf("\033[0;37m\nft_strnstr:");
const char	*ft_needlefound = ft_strnstr("Hello World", "llo", 7);
const char	*needle_found = strnstr("Hello World", "llo", 7);
if (strcmp(ft_needlefound, needle_found) == 0)
	log_tick();
else
	log_error("Not correct");

/* ft_atoi */
printf("\033[0;37m\nft_atoi:");
int	my_atoi = ft_atoi("-1234");
int	std_atoi = atoi("-1234");
if (my_atoi == std_atoi)
	log_tick();
else
{
	log_error("Not matching with atoi: ");
	printf("%d vs %d", my_atoi, std_atoi);
}

	/*  End of function */
	return (0);
}
