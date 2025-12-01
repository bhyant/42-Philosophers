/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:14:02 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/12/01 03:46:11 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *threads)
{
	t_philo	*philo;

	philo = (t_philo *)threads;
	if (philo->data->nb_philo == 1)
	{
		return (print_status(philo, FORK), ft_usleep(philo->data->time_to_die),
			NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2);
	while (1)
	{
		if (!simulation_is_on(philo->data))
			break ;
		philo_eat(philo);
		if (!simulation_is_on(philo->data))
			break ;
		philo_sleep(philo);
		if (!simulation_is_on(philo->data))
			break ;
		philo_think(philo);
		if (!simulation_is_on(philo->data))
			break ;
	}
	return (NULL);
}
