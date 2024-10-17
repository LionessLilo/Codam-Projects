/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strtrim_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/16 12:09:02 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/16 15:13:59 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main() {
    // Test cases
    char *result;
    
    // Test case 1
    result = ft_strtrim("***Hello, World!***", "* !");
    printf("Input: '***Hello, World!***'\nTrimmed: '%s'\n\n", result);
    free(result);  // Don't forget to free the allocated memory!

    // Test case 2
    result = ft_strtrim("   Leading and trailing spaces   ", " ");
    printf("Input: '   Leading and trailing spaces   '\nTrimmed: '%s'\n\n", result);
    free(result);

    // Test case 3
    result = ft_strtrim("###C Programming###", "#");
    printf("Input: '###C Programming###'\nTrimmed: '%s'\n\n", result);
    free(result);

    // Test case 4 - No characters to trim
    result = ft_strtrim("No trim needed", " ");
    printf("Input: 'No trim needed'\nTrimmed: '%s'\n\n", result);
    free(result);

    // Test case 5 - Empty string
    result = ft_strtrim("", " ");
    printf("Input: ''\nTrimmed: '%s'\n\n", result);
    free(result);

    return 0;
}
