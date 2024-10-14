/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memchr_tests.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 18:10:57 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/11 18:17:03 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    // Test cases
    const char *test_str1 = "Hello, world!";
    const char *test_str2 = "Another test string.";
    const char *test_str3 = "";
    const char *test_str4 = "A string with spaces.";
    
    // Test case 1: Find 'w' in "Hello, world!"
    char *result1 = (char *)ft_memchr(test_str1, 'w', strlen(test_str1));
    printf("Test 1: %s\n", result1 ? result1 : "Not found"); // Expected: "world!"

    // Test case 2: Find 'A' in "Another test string."
    char *result2 = (char *)ft_memchr(test_str2, 'A', strlen(test_str2));
    printf("Test 2: %s\n", result2 ? result2 : "Not found"); // Expected: "Another test string."

    // Test case 3: Find 'z' in "Another test string." (not present)
    char *result3 = (char *)ft_memchr(test_str2, 'z', strlen(test_str2));
    printf("Test 3: %s\n", result3 ? result3 : "Not found"); // Expected: "Not found"

    // Test case 4: Find ' ' in "A string with spaces."
    char *result4 = (char *)ft_memchr(test_str4, ' ', strlen(test_str4));
    printf("Test 4: %s\n", result4 ? result4 : "Not found"); // Expected: " string with spaces."

    // Test case 5: Edge case - empty string
    char *result5 = (char *)ft_memchr(test_str3, 'a', 0);
    printf("Test 5: %s\n", result5 ? result5 : "Not found"); // Expected: "Not found"

    // Test case 6: Find 'H' in "Hello, world!"
    char *result6 = (char *)ft_memchr(test_str1, 'H', strlen(test_str1));
    printf("Test 6: %s\n", result6 ? result6 : "Not found"); // Expected: "Hello, world!"

    return 0;
}
