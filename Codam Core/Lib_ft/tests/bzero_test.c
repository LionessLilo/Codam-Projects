/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bzero_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 10:08:21 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/14 11:21:21 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void) 
{
    char buffer[20] = "Hello, World!";
    
    printf("Before ft_bzero: %s\n", buffer);
    ft_bzero(buffer, 3);
    printf("\nAfter ft_bzero: %s\n", buffer + 3);

    return 0;
}
