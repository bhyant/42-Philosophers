/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:33:05 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/11/30 22:30:43 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

# define FORK "has taken a fork"
# define THINK "is thinking"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define DIED "died"

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	long			start_time;
	int				philo_is_dead;
	int				all_have_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_t		monitor;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			last_meal_time;
	int				meals_eaten;
	int				left_fork;
	int				right_fork;
	t_data			*data;
}	t_philo;

// Parsing
int		parse_args(int ac, char **av, t_data *data);

// Init
int		init_mutex(t_data *data);
int		init_data(t_data *data);
int		init_philos(t_philo **philos, t_data *data);

// Actions
int		take_forks(t_philo *philo);
void	release_forks(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

// Routine
void	*routine(void *threads);

// Thread
int		create_threads(t_philo *philos, t_data *data);
int		join_threads(t_philo *philos, t_data *data);

// Monitor
int		check_is_dead(t_philo *philos, t_data *data);
int		check_all_ate(t_philo *philo, t_data *data);
void	*monitoring(void *t);

// Utils
long	get_time(void);
int		simulation_is_on(t_data *data);
void	print_status(t_philo *philo, char *status);
void	ft_usleep(long time);
int		error_msg(char *str);

// Cleanup
void	destroy_mutex(t_data *data);
void	clean_all(t_philo *philos, t_data *data);

#endif
