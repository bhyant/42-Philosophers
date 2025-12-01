/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 23:14:24 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/11/30 22:32:10 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eat(t_philo *philo)
{
	if (!simulation_is_on(philo->data))
		return ;
	if (!take_forks(philo))
		return ;
	if (!simulation_is_on(philo->data))
	{
		release_forks(philo);
		return ;
	}
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	ft_usleep(philo->data->time_to_eat);
	if (!simulation_is_on(philo->data))
	{
		release_forks(philo);
		return ;
	}
	release_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	if (!simulation_is_on(philo->data))
		return ;
	print_status(philo, SLEEP);
	ft_usleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	long	think_time;

	print_status(philo, THINK);
	if (philo->data->nb_philo % 2 == 0)
		return ;
	think_time = philo->data->time_to_die - philo->data->time_to_eat
		- philo->data->time_to_sleep;
	if (think_time < 0)
		think_time = 0;
	if (think_time == 0)
		return ;
	if (think_time > 1)
		think_time = think_time * 0.5;
	if (think_time > 600)
		think_time = 200;
	ft_usleep(think_time);
}
