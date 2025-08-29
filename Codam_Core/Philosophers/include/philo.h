/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:25:35 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/26 11:09:15 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 2

typedef struct s_philosopher	t_philosopher;
typedef struct timeval			t_time;

typedef struct s_whiteboard
{
	int				nbr_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	t_time			current_time;
	int				is_dead;
	int				event_start;
	t_time			event_start_time;
	pthread_mutex_t	*protect_forks_ptr;
	pthread_mutex_t	protect_print;
	pthread_mutex_t	protect_dead;
	pthread_mutex_t	protect_door;
	t_philosopher	*philosophers;
}					t_whiteboard;

typedef struct s_philosopher
{
	int				id;
	int				nbr_meals_eaten;
	t_time			time_last_ate;
	pthread_t		thread;
	pthread_mutex_t	*left_fork_ptr;
	pthread_mutex_t	*right_fork_ptr;
	t_whiteboard	*check_whiteboard_ptr;
}					t_philosopher;

/* Src Functions */
/* Input checks*/
int			input_checks(int argc, char **argv);

/* Init */
int			init_whiteboard(t_whiteboard **whiteboard,
				char **input_list, int argc);

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
void		handle_death(t_philosopher *philosopher);

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
int			pick_up_forks(t_philosopher *philosopher);

/* Monitor */
int			monitor_routine(void);
int			will_die(t_philosopher *philosopher, unsigned int routine_time);

#endif