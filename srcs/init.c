/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:12:39 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/11/26 08:12:40 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
	 return (0);
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL)!= 0)
			return (error_msg("Failed to init Forks"));
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (error_msg("Failed to init Print Mutex"));
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (error_msg("Failed to init Death Mutex"));
	if (pthread_mutex_init(&data->meal_mutex, NULL) != 0)
		return (error_msg("Failed to init Meal Mutex"));
	return (1);
}

int	init_data(t_data *data)
{
	data->philo_is_dead = 0;
	data->all_have_eat = 0;
	data->start_time = get_time();
	data->forks = NULL;
	if (!init_mutex(data))
		return (0);
	return (1);
}

int	init_philos(t_philo **philos, t_data *data)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!*philos)
		return (0);
	while (i < data->nb_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].left_fork = i;
		(*philos)[i].right_fork = (i + 1) % data->nb_philo;
		(*philos)[i].last_meal_time = get_time();
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].data = data;
		i++;
	}
	return (1);
}

