/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:08:25 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/11/27 19:09:04 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
			return (error_msg("Failed To create Philo"));
		i++;
	}
	return (0);
}

int	join_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

