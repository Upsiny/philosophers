/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:55:40 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/28 15:53:28 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo	*ft_new_philo(t_data *data, int i)
{
	t_philo			*philo;
	struct timeval	time;

	gettimeofday(&time, NULL);
	philo = malloc(sizeof(t_philo));
	philo->id = i;
	data->philo[i] = philo;
	philo->data = data;
	philo->last_eat = data->time_start
		+ (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	return (philo);
}

void	*ft_new_thread(void *philo)
{
	ft_start_routine(philo);
	return (NULL);
}

void	ft_create_philos(t_data *data)
{
	int				i;
	struct timeval	time;

	data->is_alive = 1;
	i = 1;
	data->end_routine = 0;
	pthread_mutex_init(data->for_death, NULL);
	gettimeofday(&time, NULL);
	data->time_start = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	while (data->nb_philo >= i)
	{
		data->philo[i] = ft_new_philo(data, i);
		pthread_mutex_init(&data->straw[i], NULL);
		pthread_create(&data->tid[i], NULL, ft_new_thread, data->philo[i]);
		i++;
	}
	pthread_create(&data->death, NULL, ft_death, data);
	data->tid[i] = NULL;
	data->philo[i] = NULL;
	while (i > 0)
	{
		pthread_join(data->tid[i], NULL);
		i--;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mutex = malloc(sizeof(pthread_mutex_t));
	data->for_death = malloc(sizeof(pthread_mutex_t));
	if (ft_parse(ac, av, data) != 1)
		return (0);
	if (data->must_eat != 0)
		ft_create_philos(data);
	pthread_join(data->death, NULL);
}
