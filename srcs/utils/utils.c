/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:28:34 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/11/29 01:16:56 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	simulation_is_on(t_data *data)
{

	pthread_mutex_lock(&data->death_mutex);
	if (data->philo_is_dead == 1)
	{
		pthread_mutex_unlock(&data->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (1);
}

void	print_status(t_philo *philo, char *status)
{
	long	time;
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!simulation_is_on(philo->data))
	{
		pthread_mutex_unlock(&philo->data->print_mutex);
		return ;
	}
	time = get_time() - philo->data->start_time;
	printf("%ld %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	ft_usleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

