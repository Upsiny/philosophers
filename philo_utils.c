/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utilic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:46:51 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/22 11:48:01 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_parse(int ac, char **av, t_data *data)
{
	if (ac >= 5 && ac <= 6)
	{
		data->nb_philo = ft_atoi(av[1]);
		data->time_to_die = ft_atoi(av[2]);
		data->time_to_eat = ft_atoi(av[3]);
		data->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			data->must_eat = ft_atoi(av[5]);
		pthread_mutex_init(data->mutex, NULL);
		return (1);
	}
	return (0);
}

long long int	ft_time()
{
	struct	timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000);
}

void	ft_usleep(int i)
{
	long long int	need;
	struct	timeval	time;

	gettimeofday(&time, NULL);
	need = ((time.tv_sec) * 1000 + (time.tv_usec) / 1000) + i;
	while (ft_time() <= need)
	{
		usleep(50);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	result *= neg;
	return (result);
}

void	print_time(long long int start)
{
	struct	timeval	current_time;
	long long int	now;

	gettimeofday(&current_time, NULL);
	now = (current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000;
	printf("%lld ", now - start);
}
