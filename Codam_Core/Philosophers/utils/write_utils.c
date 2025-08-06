/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/06 16:51:10 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/06 17:10:04 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	len_s;

	len_s = ft_strlen((char *)s);
	new_s = malloc (sizeof(char) * (len_s + 1));
	if (!new_s)
		return (NULL);
	ft_memcpy(new_s, s, len_s);
	new_s[len_s] = '\0';
	return (new_s);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
