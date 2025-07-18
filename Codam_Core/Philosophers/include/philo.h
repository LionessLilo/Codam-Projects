/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:25:35 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/17 18:08:39 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_whiteboard
{
	int				nbr_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	int				is_dead;
	long			event_start;
	pthread_mutex_t	*protect_forks_ptr;
	pthread_mutex_t	protect_print;
	pthread_mutex_t	protect_dead;
	t_philosopher	*philosophers;
}	t_whiteboard;

typedef struct s_philosopher
{
	int				id;
	int				nbr_meals_eaten;
	long			time_last_ate;
	pthread_t		thread;
	pthread_mutex_t	*left_fork_ptr;
	pthread_mutex_t	*right_fork_ptr;
	t_whiteboard	*check_whiteboard_ptr;
}					t_philosopher;

/* Src Functions */
int				input_checks(int argc, char **argv);
t_whiteboard	*init_whiteboard(char **input_list);

/* Util Functions */
char		**ft_split(char const *str, char chr);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *string);
int			ft_isdigit(int c);
long int	ft_atol(const char *str);
void		report_error(int code);
size_t		find_list_size(const char *str, char chr);
void		cleanup_list(char **list_start);



#endif