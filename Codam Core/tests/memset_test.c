/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memset_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 09:28:35 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/10 09:28:48 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	main(void)
{
    char buffer[20] = "Hello, World!";
    
    printf("Before ft_memset: %s\n", buffer);
    ft_memset(buffer, '*', 3);
    printf("\nAfter ft_memset: %s\n", buffer);

    return 0;
}