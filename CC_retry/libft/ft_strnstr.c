/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/19 13:36:32 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/19 19:12:40 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

const char	*ft_strnstr(const char *haystack,
						const char *needle,
						size_t size)
{
	const char	*search_end;
	const char	*cursor;
	size_t		needle_len;

	if (*needle == '\0')
		return ((const char *)haystack);
	if (size == 0)
		return (NULL);
	search_end = haystack + size;
	cursor = (const char *)haystack;
	needle_len = ft_strlen(needle);
	while (*cursor && cursor + needle_len <= search_end)
	{
		if (ft_strncmp(cursor, needle, needle_len) == 0)
			return (cursor);
		cursor++;
	}
	return (NULL);
}
