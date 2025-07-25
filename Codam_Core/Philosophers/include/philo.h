/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:25:35 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/24 17:53:46 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philosopher	t_philosopher;

typedef struct s_whiteboard
{
	size_t			nbr_philosophers;
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
	TRUE = 1,
	FALSE = 2,
	GEN_ERROR = 3,
	MALLOC_FAIL = 5,
	THREAD_INIT_ERROR = 6,
	THREAD_ERROR = 7,
	MUTEX_INIT_ERROR = 8,
	MUTEX_LOCK_ERROR = 9,
	MUTEX_UNLOCK_ERROR = 10,
	USER_INPUT_ERROR = 41,
}	t_error;

/* Src Functions */
t_error		input_checks(int argc, char **argv);
t_error		init_whiteboard(t_whiteboard **whiteboard, char **input_list);
void		cleanup_list(char **list_start);
void		clean_whiteboard(t_whiteboard **whiteboard);
/* Util Functions */
char		**ft_split(char const *str, char chr);
void		free_list(char **list_start, char **list);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *string);
int			ft_isdigit(int c);
long int	ft_atol(const char *str);
void		report_error(int code);
void		error_message(char *message);
size_t		find_list_size(const char *str, char chr);
void		clean_forks(t_whiteboard **whiteboard);
void		clean_philosophers(t_whiteboard **whiteboard);
void		free_and_null(void *incoming_memory);

#endif