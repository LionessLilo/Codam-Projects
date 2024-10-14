/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strncmp_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 17:24:22 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/11 17:28:06 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    // Test cases according to strncmp manual
    struct {
        const char *str1;
        const char *str2;
        size_t n;
    } tests[] = {
        {"hello", "hello", 5},          // Equal strings
        {"hello", "hello", 3},          // Equal strings (partial)
        {"hello", "world", 5},          // Different strings
        {"apple", "banana", 5},         // Different strings
        {"abc", "abcdef", 3},           // Prefix match
        {"abcdef", "abc", 6},           // Longer first string
        {"abcd", "abcd", 4},            // Exactly equal strings
        {"abcd", "abce", 4},            // Single character difference
        {"", "abcd", 4},                // Compare empty string with non-empty
        {"abcd", "", 4},                // Compare non-empty with empty
        {"abc", "ABC", 3},              // Case-sensitive comparison
        {"abc", "abcde", 5},            // Partial match (first string is shorter)
        {"abc", "abc", 0},              // Compare zero characters
        {"abc", "abd", 3},              // Near match with a single character off
        {"abcdef", "abcdefg", 7},       // Strings of different lengths
    };

    int test_count = sizeof(tests) / sizeof(tests[0]);
    int passed_count = 0;

    for (int i = 0; i < test_count; i++) {
        int result = ft_strncmp(tests[i].str1, tests[i].str2, tests[i].n);
        int expected = strncmp(tests[i].str1, tests[i].str2, tests[i].n);

        if ((result == 0 && expected == 0) || (result < 0 && expected < 0) || (result > 0 && expected > 0)) {
            printf("Test %d passed: ft_strncmp(\"%s\", \"%s\", %zu) = %d (expected %d)\n", 
                   i + 1, tests[i].str1, tests[i].str2, tests[i].n, result, expected);
            passed_count++;
        } else {
            printf("Test %d failed: ft_strncmp(\"%s\", \"%s\", %zu) = %d (expected %d)\n", 
                   i + 1, tests[i].str1, tests[i].str2, tests[i].n, result, expected);
        }
    }

    printf("\nPassed %d/%d tests.\n", passed_count, test_count);
    return 0;
}