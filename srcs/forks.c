/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:30:00 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/11/30 22:32:08 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	take_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_lock(&philo->data->forks[fork_id]);
	if (!simulation_is_on(philo->data))
	{
		pthread_mutex_unlock(&philo->data->forks[fork_id]);
		return (0);
	}
	print_status(philo, FORK);
	return (1);
}

static int	take_even_forks(t_philo *philo)
{
	if (!take_fork(philo, philo->left_fork))
		return (0);
	if (!take_fork(philo, philo->right_fork))
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		return (0);
	}
	return (1);
}

static int	take_odd_forks(t_philo *philo)
{
	if (!take_fork(philo, philo->right_fork))
		return (0);
	if (!take_fork(philo, philo->left_fork))
	{
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		return (0);
	}
	return (1);
}

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		return (take_even_forks(philo));
	else
		return (take_odd_forks(philo));
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}
