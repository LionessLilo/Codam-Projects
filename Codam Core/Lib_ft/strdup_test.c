/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strdup_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 12:33:41 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/15 12:51:41 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"  // Ensure this header includes declarations for ft_strlen and ft_memcpy

int main() {
    // Test case 1: Basic functionality
    char *original1 = "Hello, world!";
    char *duplicate1 = ft_strdup(original1);
    if (duplicate1) {
        printf("Original: %s\nDuplicate: %s\n\n", original1, duplicate1);
        free(duplicate1);  // Freeing allocated memory
    } else {
        printf("Failed to allocate memory for: %s\n\n", original1);
    }

    // Test case 2: Empty string
    char *original2 = "";
    char *duplicate2 = ft_strdup(original2);
    if (duplicate2) {
        printf("Original: '%s'\nDuplicate: '%s'\n\n", original2, duplicate2);
        free(duplicate2);
    } else {
        printf("Failed to allocate memory for: '%s'\n\n", original2);
    }

    // Test case 4: Special characters
    char *original3 = "Special characters: @#&*()";
    char *duplicate3 = ft_strdup(original3);
    if (duplicate3) {
        printf("Original: %s\nDuplicate: %s\n\n", original3, duplicate3);
        free(duplicate3);
    } else {
        printf("Failed to allocate memory for: %s\n\n", original3);
    }

    // Test case 5: Long string
    char *original4 = "This is a very long string that is meant to test the ft_strdup function. "
                      "It should allocate enough memory and duplicate the string correctly.";
    char *duplicate4 = ft_strdup(original4);
    if (duplicate4) {
        printf("Original: %.50s...\nDuplicate: %.50s...\n\n", original4, duplicate4);
        free(duplicate4);
    } else {
        printf("Failed to allocate memory for a long string.\n\n");
    }

    return 0;
}
