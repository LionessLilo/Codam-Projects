/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:25:35 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/15 11:01:17 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
#include <sys/time.h>

# define TRUE 1
# define FALSE 2

typedef struct s_philosopher	t_philosopher;
typedef struct timeval	t_time;

typedef struct s_whiteboard
{
	size_t			nbr_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	int				current_time;
	int				is_dead;
	int				event_start;
	int				event_start_time;
	pthread_mutex_t	*protect_forks_ptr;
	pthread_mutex_t	protect_print;
	pthread_mutex_t	protect_dead;
	pthread_mutex_t	protect_door;
	t_philosopher	*philosophers;
}					t_whiteboard;

typedef struct s_philosopher
{
	size_t			id;
	int				nbr_meals_eaten;
	long			time_last_ate;
	pthread_t		thread;
	pthread_mutex_t	*left_fork_ptr;
	pthread_mutex_t	*right_fork_ptr;
	t_whiteboard	*check_whiteboard_ptr;
}					t_philosopher;

/* Src Functions */
/* Input checks*/
int			input_checks(int argc, char **argv);

/* Init */
int			init_whiteboard(t_whiteboard **whiteboard, char **input_list);

/* Cleanup*/
void		cleanup_list(char **list_start);
void		clean_whiteboard(t_whiteboard **whiteboard);
void		write_error(char *message, int error_code);

/* Event */
int			start_event(t_whiteboard *whiteboard);

/* Routine */
void		*philosopher_routine(void *thread_arg);

/* Util Functions */
/* cleanup utils */
void		clean_forks(t_whiteboard **whiteboard);
void		free_and_null(void *incoming_memory);

/* Lib utils */
size_t		ft_strlen(const char *string);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
long int	ft_atol(const char *str);
int			ft_isdigit(int c);
char		*ft_strdup(const char *s);

/* ft_split */
char		**ft_split(char const *str, char chr);
void		free_list(char **list_start, char **list);
size_t		find_list_size(const char *str, char chr);

/* ft_itoa*/
char		*ft_itoa(int nbr);

/* Write utils*/
char		*ft_strdup(const char *s);

/* Routine_utils*/
int			print_action(t_philosopher *philosopher, char *action);

/* Monitor */
int			monitor_routine(void);
int			check_if_dead(t_philosopher *philosopher, int routine_time);

#endif