/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:12:11 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/11/30 22:25:43 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;

	if (!parse_args(ac, av, &data))
		return (1);
	if (!init_data(&data))
		return (1);
	if (!init_philos(&philos, &data))
		return (clean_all(NULL, &data), 1);
	if (!create_threads(philos, &data))
		return (clean_all(philos, &data), 1);
	join_threads(philos, &data);
	clean_all(philos, &data);
	return (0);
}
