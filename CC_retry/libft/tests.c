/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 11:51:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/06 20:30:25 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

static void	log_tick(void)
{
	printf("\033[0;32m ✔ \033[0;37m \n");
}

static void	log_error(char *message)
{
	printf("\033[0;31m%s\n\n\033[0;37m", message);
}

int	main(void)
{
	/* ft_isalpha */
	printf("\033[0;37mft_isalpha:\n");
	if (ft_isalpha('A') == 1)
		log_tick();
	else
		log_error("Says A is not alpha");
	if (ft_isalpha(1) == 0)
		log_tick();
	else
		log_error("Says number is alpha");

	/* ft_isdigit */
	printf("ft_isdigit:\n");
	if (ft_isdigit('1') == 1)
		log_tick();
	else
		log_error("Says '1' is not a digit");
	if (ft_isdigit(2) == 0)
		log_tick();
	else
		log_error("Says an integer is a digit");
	
	/* ft_ft_isalnum */
	printf("ft_ft_isalnum\n");
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
	printf("ft_isprint:\n");
	if (ft_isprint('\n') == 0)
		log_tick();
	else
		log_error("Thinks new line is printable");
	if (ft_isprint('~') == 1)
		log_tick();
	else
		log_error("Does not think that '~' is not printable");
	
	/* ft_strlen */
	printf("ft_strlen:\n");
	if (ft_strlen("Hello") == 5)
		log_tick();
	else
		log_error("Length is incorrect");
	
	/* ft_memset */
	printf("ft_memset:\n");
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
	printf("ft_bzero:\n");
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
	printf("ft_memcpy:\n");
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
	printf("ft_memmove:\n");
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
	printf("ft_strlcpy:\n");
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
	printf("ft_strlcat:\n");

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
printf("\033[0;37mft_toupper:\n");
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
printf("\033[0;37mft_tolower:\n");
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
printf("\033[0;37mft_strchr:\n");
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
printf("\033[0;37mft_strrchr:\n");
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
printf("\033[0;37mft_strncmp:\n");
int ft_strncmp_result = ft_strncmp("Hello", "Help!", 4);
if (ft_strncmp_result == -4)
	log_tick();
else
{
	log_error("ft_strncmp result does not match strncmp result");
	printf("%d", ft_strncmp_result);
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
printf("\033[0;37mft_memchr:\n");
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
printf("\033[0;37mft_memcmp:\n");
char *ft_memcmp_ptr = ft_memcmp("Hello", "Help!", 5);
char *man_memcmp = memcmp("Hello", "Help!", 5);
if (memcmp(ft_memchr_ptr, man_memchr, 1) == 0)
	log_tick();
else
{
	log_error("Not returning the correct pointer");
	printf("%p", (void *)ft_returned_ptr);
}

	/*  End of function */
	return (0);
}
