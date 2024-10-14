/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memmove_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 17:04:32 by lilo          #+#    #+#                 */
/*   Updated: 2024/10/14 15:33:04 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

int main() {
    // Test case 1: Non-overlapping memory regions
    char src1[] = "Hello, World!";
    char dest1[20];

    printf("Before ft_memmove (non-overlapping):\n");
    printf("Source: %s\n", src1);
    printf("Destination (initial): %s\n", dest1);

    ft_memmove(dest1, src1, strlen(src1) + 1); // +1 to copy the null terminator

    printf("After ft_memmove (non-overlapping):\n");
    printf("Destination: %s\n", dest1);

    // Test case 3: Zero bytes to move
    char str3[] = "No change expected";

    printf("\nBefore ft_memmove (zero bytes):\n");
    printf("String: %s\n", str3);

    ft_memmove(str3, str3, 0); // No effect, zero bytes to move

    printf("After ft_memmove (zero bytes):\n");
    printf("String: %s\n", str3); // Should remain unchanged

    return 0;
}