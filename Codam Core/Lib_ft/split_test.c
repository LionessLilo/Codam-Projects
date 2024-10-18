/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 07:49:51 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/18 07:49:54 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Prototype of the ft_split function
char **ft_split(char const *s, char c);

// Function to free the allocated memory
void free_split(char **split)
{
    int i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

// Function to print the resulting array of strings
void print_split(char **split)
{
    int i = 0;
    while (split[i])
    {
        printf("String %d: %s\n", i, split[i]);
        i++;
    }
}

int main(void)
{
    char *str = "Hello,world,this,is,a,test";
    char delimiter = ',';

    // Call ft_split and store the result
    char **result = ft_split(str, delimiter);

    // Check if the result is not NULL
    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print the split strings
    print_split(result);

    // Free the allocated memory
    free_split(result);

    return 0;
}
