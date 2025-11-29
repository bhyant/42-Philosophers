/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:14:02 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/11/26 08:14:03 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *threads)
{
	t_philo	*philo;

	philo = (t_philo *)threads;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (!simulation_is_on(philo->data))
			break ;
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

