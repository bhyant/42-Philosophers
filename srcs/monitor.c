/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:12:58 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/11/29 01:26:09 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_is_dead(t_philo *philos, t_data *data)
{
	int		i;
	long	current_time;
	long	time_no_meal;

	i = 0;
	while (i < data->nb_philo)
	{
		current_time = get_time();
		pthread_mutex_lock(&data->meal_mutex);
		time_no_meal = current_time - philos[i].last_meal_time;
		pthread_mutex_unlock(&data->meal_mutex);
		if (time_no_meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->death_mutex);
			data->philo_is_dead = 1;
			pthread_mutex_unlock(&data->death_mutex);
			pthread_mutex_lock(&data->print_mutex);
			printf("%ld %d died\n", current_time - data->start_time, philos[i].id);
			pthread_mutex_unlock(&data->print_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_all_ate(t_philo *philo, t_data *data)
{
	int	i;
	int	all_ate;

	if (data->must_eat_count == -1)
		return (0);
	i = 0;
	all_ate = 1;
	while (i < data->nb_philo)
	{
		if (philo[i].meals_eaten < data->must_eat_count)
			return (0);
		i++;
	}
	if (all_ate)
	{
		pthread_mutex_lock(&data->death_mutex);
		data->philo_is_dead = 1;
		pthread_mutex_unlock(&data->death_mutex);
	}
	return (1);
}

void	*monitoring(void *t)
{
	t_philo	*philos;

	philos = (t_philo *)t;
	while (1)
	{
		if (check_is_dead(philos, philos[0].data))
			break ;
		if (check_all_ate(philos, philos[0].data))
			break ;
		usleep(1000);
	}
	return (NULL);
}

