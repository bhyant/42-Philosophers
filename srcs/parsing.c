/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:12:14 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/11/26 08:12:15 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

static bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	ft_atoi_safe(char *str)
{
	long	res;
	int		i;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)res);
}

static int	check_args(int ac, char **av, t_data *data)
{
	(void)ac;
	data->nb_philo = ft_atoi_safe(av[1]);
	data->time_to_die = ft_atoi_safe(av[2]);
	data->time_to_eat = ft_atoi_safe(av[3]);
	data->time_to_sleep = ft_atoi_safe(av[4]);
	if (data->nb_philo <= 0)
		return (error_msg("Number of philosophers must be > 0"));
	if (data->time_to_die <= 0)
		return (error_msg("time_to_die must be > 0"));
	if (data->time_to_eat <= 0)
		return (error_msg("time_to_eat must be > 0"));
	if (data->time_to_sleep <= 0)
		return (error_msg("time_to_sleep must be > 0"));
	return (1);
}

int	parse_args(int ac, char **av, t_data *data)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (error_msg("Wrong Number of Args"));
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
			return (error_msg("Args Must be positive numbers"));
		i++;
	}
	if (!check_args(ac, av, data))
		return (0);
	if (ac == 6)
	{
		data->must_eat_count = ft_atoi_safe(av[5]);
		if (data->must_eat_count <= 0)
			return (error_msg("must_eat_count must be > 0"));
	}
	else
		data->must_eat_count = -1;
	return (1);
}

