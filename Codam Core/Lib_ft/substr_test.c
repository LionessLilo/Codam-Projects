/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substr_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:22:00 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/15 14:30:41 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>  // For malloc, free
#include <stdio.h>   // For printf
#include <string.h>  // For strlen

// Function prototype for ft_substr
char *ft_substr(char const *s, unsigned int start, size_t len);

int main() {
    char *string = "Hello, World!";
    char *substring;

    // Test 1: Normal case
    substring = ft_substr(string, 7, 5);
    if (substring) {  // Ensure it's not NULL
        printf("Test 1: %s\n", substring);  // Output: World
        free(substring);
    } else {
        printf("Test 1: Allocation failed.\n");
    }

    // Test 2: Start index is greater than string length
    substring = ft_substr(string, 20, 5);
    if (substring) {
        printf("Test 2: %s\n", substring);  // Output: (empty string)
        free(substring);
    } else {
        printf("Test 2: Allocation failed.\n");
    }

    // Test 3: Len exceeds available characters
    substring = ft_substr(string, 7, 50);
    if (substring) {
        printf("Test 3: %s\n", substring);  // Output: World!
        free(substring);
    } else {
        printf("Test 3: Allocation failed.\n");
    }

    return 0;
}
