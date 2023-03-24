/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:30:40 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/22 15:26:32 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_print(char *msg, pthread_mutex_t *mutex, int id, t_philo *philo)
{
	pthread_mutex_lock(mutex);
	print_time(philo->data->time_start);
	printf("%d %s\n", id, msg);
	pthread_mutex_unlock(mutex);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->straw[philo->id -1]);
	ft_print("has taken a fork", philo->data->mutex, philo->id, philo);
	if (philo->id == philo->data->nb_philo)
	{
		pthread_mutex_lock(&philo->data->straw[0]);
		ft_print("has taken a fork", philo->data->mutex, philo->id, philo);
	}
	else
	{
		pthread_mutex_lock(&philo->data->straw[philo->id]);
		ft_print("has taken a fork", philo->data->mutex, philo->id, philo);
	}
	ft_print("is eating", philo->data->mutex, philo->id, philo);
	philo->last_eat = ft_time();
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->straw[philo->id - 1]);
	if (philo->id == philo->data->nb_philo)
		pthread_mutex_unlock(&philo->data->straw[0]);
	else
		pthread_mutex_unlock(&philo->data->straw[philo->id]);
}

void	ft_sleep(t_philo *philo)
{
	ft_print("is sleeping", philo->data->mutex, philo->id, philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print("is thinking", philo->data->mutex, philo->id, philo);
}

void	ft_start_routine(t_philo *philo)
{
	int	i;

	i = 1;
	if (philo->id % 2 != 1)
	{
		ft_think(philo);
		ft_usleep(100);
	}
	while (philo->data->must_eat >= i)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
		i++;
	}
}
