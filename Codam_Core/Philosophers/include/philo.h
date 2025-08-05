/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:25:35 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/05 15:45:24 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>

# define TRUE 1
# define FALSE 2

typedef struct s_philosopher	t_philosopher;

typedef struct s_whiteboard
{
	size_t			nbr_philosophers;
	int				time_to_die;
	int				time_to_eat;
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

typedef enum e_error
{
	FUNCT_ERROR = -1,
	SUCCESS = 0,
	GEN_ERROR = 3,
	MALLOC_FAIL = 5,
	THREAD_INIT_ERROR = 6,
	THREAD_JOIN_ERROR = 7,
	THREAD_ERROR = 8,
	MUTEX_INIT_ERROR = 9,
	MUTEX_LOCK_ERROR = 10,
	MUTEX_UNLOCK_ERROR = 11,
	USER_INPUT_ERROR = 41,
}	t_error;

/* Src Functions */
/* Input checks*/
t_error		input_checks(int argc, char **argv);

/* Init */
t_error		init_whiteboard(t_whiteboard **whiteboard, char **input_list);

/* Cleanup*/
void		cleanup_list(char **list_start);
void		clean_whiteboard(t_whiteboard **whiteboard);

/* Event */
t_error		start_event(t_whiteboard *whiteboard);

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

/* ft_split */
char		**ft_split(char const *str, char chr);
void		free_list(char **list_start, char **list);
size_t		find_list_size(const char *str, char chr);

/* Routine_utils*/
t_error	print_action(t_philosopher *philosopher, char *action);

#endif