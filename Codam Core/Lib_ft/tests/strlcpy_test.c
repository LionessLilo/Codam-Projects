/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlcpy_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 23:02:23 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/14 10:58:13 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    char src[] = "Hello, world!";
    char dest_small[5];
    size_t result;
    
    result = ft_strlcpy(dest_small, src, sizeof(dest_small));
    printf("Test - Expected length: %lu, Copied length: %lu, Destination string: \"%s\"\n", strlen(src), result, dest_small);
    return 0;
}