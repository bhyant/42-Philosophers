/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:12:11 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/11/26 08:12:12 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	int main(int ac, char **av)
{
	t_data	data;
	t_data	*philos;

	if (!parse_args(ac, av, &data))
		return (1);
	if (!init_data(&data))
		return (1);
	if (!init_philos(&philos, &data))
		return (cleanup(NULL, &data), 1);
	if (!create_threads(philos, &data))
		return (cleanup(philos, &data), 1);
	wait_threads(philos, &data);
	cleanup(philos, &data);
	return (0);
}

