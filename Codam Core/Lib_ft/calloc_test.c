/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calloc_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 10:56:51 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/15 11:09:52 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "libft.h"

int main(void)
{
    // Test case 1: Standard allocation
    size_t num1 = 5, size1 = sizeof(int);
    int *arr1 = (int *)ft_calloc(num1, size1);
    if (arr1) {
        printf("Test case 1: Standard allocation (5 ints): ");
        for (size_t i = 0; i < num1; i++) {
            printf("%d ", arr1[i]); // Should print 0 0 0 0 0
        }
        printf("\n");
        free(arr1);
    } else {
        printf("Allocation failed for test case 1\n");
    }

    // Test case 2: Zero allocation (num = 0)
    size_t num2 = 0, size2 = sizeof(int);
    int *arr2 = (int *)ft_calloc(num2, size2);
    if (arr2 == NULL) {
        printf("Test case 2: Allocation failed as expected for zero allocation.\n");
    } else {
        printf("Test case 2: Unexpected allocation success, pointer: %p\n", (void *)arr2);
        free(arr2);
    }

    // Test case 3: Large allocation
    size_t num3 = 1000000, size3 = sizeof(int);
    int *arr3 = (int *)ft_calloc(num3, size3);
    if (arr3) {
        printf("Test case 3: Allocation succeeded for 1,000,000 ints, pointer: %p\n", (void *)arr3);
        // Optionally check some values
        if (arr3[0] == 0 && arr3[num3 - 1] == 0) {
            printf("Test case 3: All values initialized to zero.\n");
        }
        free(arr3);
    } else {
        printf("Allocation failed for test case 3\n");
    }

    // Test case 4: Overflow handling (calculation for SIZE_MAX)
    size_t num4 = (size_t)(-1); // Calculate max value for size_t
    size_t size4 = 1; // This will likely overflow
    void *arr4 = ft_calloc(num4, size4);
    if (arr4 == NULL) {
        printf("Test case 4: Allocation failed as expected due to overflow.\n");
    } else {
        printf("Test case 4: Unexpected allocation success, pointer: %p\n", (void *)arr4);
        free(arr4);
    }

    // Test case 5: Non-standard size
    size_t num5 = 10, size5 = sizeof(char);
    char *arr5 = (char *)ft_calloc(num5, size5);
    if (arr5) {
        printf("Test case 5: Allocation of 10 chars: ");
        for (size_t i = 0; i < num5; i++) {
            printf("'%c' ", arr5[i]); // Should print empty chars (null terminators)
        }
        printf("\n");
        free(arr5);
    } else {
        printf("Allocation failed for test case 5\n");
    }

    return 0;
}
