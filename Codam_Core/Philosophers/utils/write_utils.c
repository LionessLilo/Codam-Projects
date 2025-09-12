/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/06 16:51:10 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/12 18:28:13 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
int		print_action(t_philosopher *philosopher, char *action);

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	len_s;

	len_s = ft_strlen((char *)s);
	new_s = malloc(sizeof(char) * (len_s + 1));
	if (!new_s)
		return (NULL);
	ft_memcpy(new_s, s, len_s);
	new_s[len_s] = '\0';
	return (new_s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
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

int	print_action(t_philosopher *philosopher, char *action)
{
	long			get_timestamp;
	t_whiteboard	*whiteboard;

	whiteboard = philosopher->check_whiteboard_ptr;
	if (pthread_mutex_lock(&whiteboard->protect_print) != 0)
		return (write_error("Print mutex failed to lock", 7), -1);
	if (whiteboard->is_dead == TRUE && strcmp(action, "died") != 0)
	{
		pthread_mutex_unlock(&whiteboard->protect_print);
		return (-1);
	}
	get_timestamp = calculate_timestamp(philosopher);
	printf("%ld %d %s\n", get_timestamp, philosopher->id, action);
	if (pthread_mutex_unlock(&whiteboard->protect_print) != 0)
		return (write_error("Print mutex failed to unlock", 7), -1);
	return (0);
}
