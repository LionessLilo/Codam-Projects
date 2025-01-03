/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 20:08:49 by root          #+#    #+#                 */
/*   Updated: 2025/01/03 17:07:37 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"

int is_valid_int(const char *cchar_input_numbers);
int contains_duplicates(int *int_stack_a_array, int int_stack_size);
int validate_input(int argc, char **argv, int **int_stack_a_array, int *stack_size);

int main(int argc, char **argv)
{
    int *stack_a_array = NULL; // Pointer to hold the validated array
    int stack_size = 0;        // Variable to hold the size of the stack

    // Call validate_input to process and validate arguments
    if (!validate_input(argc, argv, &stack_a_array, &stack_size))
    {
        ft_printf("Input validation failed.\n");
        return (1);
    }

    // Print the valid numbers
    ft_printf("Validated numbers:\n");
    for (int i = 0; i < stack_size; i++)
    {
        ft_printf("%d ", stack_a_array[i]);
    }
    ft_printf("\n");

    // Free the allocated memory
    free(stack_a_array);
    return (0);
}
