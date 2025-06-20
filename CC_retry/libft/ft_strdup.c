/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/20 17:49:39 by lionesslilo   #+#    #+#                 */
/*   Updated: 2025/06/20 19:07:22 by lionesslilo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
    Returns a pointer to a new string which is a duplicate of string. It needs 
    to allocate memory for the new string and you need to free your strdup.
*/

char    *ft_strdup(const char *string)
{
    size_t  str_len;
    char    *str_duplicated;
    
    str_len = ft_strlen(string) + 1;
    str_duplicated = malloc(sizeof(char) * str_len);
    if (!str_duplicated)
        return (NULL);
    ft_memcpy(str_duplicated, string, str_len);
    return (str_duplicated);
}
