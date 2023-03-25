/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:30:40 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/25 19:22:28 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_take_straw(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->straw[philo->id -1]);
	ft_print("has taken a fork", philo->data->mutex, philo->id, philo);
	if ((philo->id == philo->data->nb_philo && !ft_check_death(philo))
		&& philo->data->nb_philo != 1)
	{
		pthread_mutex_lock(&philo->data->straw[0]);
		ft_print("has taken a fork", philo->data->mutex, philo->id, philo);
	}
	else
	{
		if (philo->data->nb_philo != 1)
		{
			pthread_mutex_lock(&philo->data->straw[philo->id]);
			ft_print("has taken a fork", philo->data->mutex, philo->id, philo);
		}
		else
			ft_usleep(philo->data->time_to_die * 2, philo->data);
	}
}

void	ft_eat(t_philo *philo)
{
	ft_take_straw(philo);
	ft_print("is eating", philo->data->mutex, philo->id, philo);
	pthread_mutex_lock(philo->data->for_death);
	philo->last_eat = ft_time();
	pthread_mutex_unlock(philo->data->for_death);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(&philo->data->straw[philo->id - 1]);
	if (philo->id == philo->data->nb_philo)
		pthread_mutex_unlock(&philo->data->straw[0]);
	else
		pthread_mutex_unlock(&philo->data->straw[philo->id]);
}

void	ft_sleep(t_philo *philo)
{
	ft_print("is sleeping", philo->data->mutex, philo->id, philo);
	ft_usleep(philo->data->time_to_sleep, philo->data);
}

int	ft_is_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->data->for_death);
	if (philo->data->is_alive != 1)
	{
		pthread_mutex_unlock(philo->data->for_death);
		return (0);
	}
	pthread_mutex_unlock(philo->data->for_death);
	return (1);
}

void	ft_start_routine(t_philo *philo)
{
	int	i;

	i = 1;
	if (philo->id % 2 != 1)
	{
		ft_print("is thinking", philo->data->mutex, philo->id, philo);
		ft_usleep(100, philo->data);
	}
	while (philo->data->must_eat != (i - 1) && ft_is_alive(philo) != 0)
	{
		if (ft_is_alive(philo) != 0)
			ft_eat(philo);
		if (ft_is_alive(philo) != 0)
			ft_sleep(philo);
		if (ft_is_alive(philo) != 0)
			ft_print("is thinking", philo->data->mutex, philo->id, philo);
		i++;
	}
	pthread_mutex_lock(philo->data->for_death);
	philo->data->end_routine++;
	pthread_mutex_unlock(philo->data->for_death);
}
