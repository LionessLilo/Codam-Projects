/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strnstr_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/14 10:57:27 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/14 15:46:17 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    // Test cases
    struct {
        const char *big;
        const char *little;
        size_t len;
        const char *expected;
    } tests[] = {
        // Test case 1: Simple case
        {"Hello, World!", "World", 13, "World!"},
        // Test case 2: Little is empty
        {"Hello, World!", "", 13, "Hello, World!"},
        // Test case 3: Big is empty
        {"", "World", 0, NULL},
        // Test case 4: Little is longer than Big
        {"Hello", "Hello, World", 5, NULL},
        // Test case 5: Match within len limit
        {"abcdefg", "cd", 7, "cdefg"}
        // Test case 6: No match within len limit
        {"abcdefg", "cd", 2, NULL},
        // Test case 7: Match at the end
        {"abcdefg", "fg", 7, "fg"},
        // Test case 8: Match at the start
        {"abcdefg", "a", 7, "abcdefg"},
        // Test case 9: Len is zero
        {"abcdefg", "a", 0, NULL},
        // Test case 10: Match when len is exact
        {"abcdefg", "abcdefg", 7, "abcdefg"},
        // Test case 11: Match when len is longer than string
        {"abcdefg", "abcdefg", 10, "abcdefg"},
    };

    // Run tests
    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        const char *result = ft_strnstr(tests[i].big, tests[i].little, tests[i].len);
        printf("Test %zu: ft_strnstr(\"%s\", \"%s\", %zu) = \"%s\"; Expected = \"%s\"\n", 
               i + 1, tests[i].big, tests[i].little, tests[i].len, 
               result ? result : "NULL", tests[i].expected ? tests[i].expected : "NULL");
    }

    return 0;
}