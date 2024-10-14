/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strchr_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 11:46:11 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/11 11:50:54 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int main(void)
{
    // Test case 1: Character found in the middle of the string
    const char *str1 = "Hello, World!";
    char *result = ft_strchr(str1, 'W');
    if (result != NULL)
        printf("Test 1: Character 'W' found at position %ld. Result: %s\n", result - str1, result);
    else
        printf("Test 1: Character 'W' not found.\n");

    // Test case 2: Character not found
    const char *str2 = "Hello, World!";
    result = ft_strchr(str2, 'z');
    if (result != NULL)
        printf("Test 2: Character 'z' found at position %ld. Result: %s\n", result - str2, result);
    else
        printf("Test 2: Character 'z' not found.\n");

    // Test case 3: Searching for the null terminator
    const char *str3 = "Hello, World!";
    result = ft_strchr(str3, '\0');
    if (result != NULL)
        printf("Test 3: Null terminator found at position %ld.\n", result - str3);
    else
        printf("Test 3: Null terminator not found.\n");

    // Test case 4: Empty string
    const char *str4 = "";
    result = ft_strchr(str4, 'H');
    if (result != NULL)
        printf("Test 4: Character 'H' found at position %ld. Result: %s\n", result - str4, result);
    else
        printf("Test 4: Character 'H' not found.\n");

    // Test case 5: Single character string
    const char *str5 = "H";
    result = ft_strchr(str5, 'H');
    if (result != NULL)
        printf("Test 5: Character 'H' found at position %ld. Result: %s\n", result - str5, result);
    else
        printf("Test 5: Character 'H' not found.\n");

    // Test case 6: Character at the end of the string
    const char *str6 = "Hello, World!";
    result = ft_strchr(str6, '!');
    if (result != NULL)
        printf("Test 6: Character '!' found at position %ld. Result: %s\n", result - str6, result);
    else
        printf("Test 6: Character '!' not found.\n");

    return 0;
}