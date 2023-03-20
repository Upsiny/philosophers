/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:30:40 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/20 17:10:01 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->data.mutex);
	printf("philo %d is eating\n", philo->id);
	ft_usleep(philo->data.time_to_eat);
	pthread_mutex_unlock(philo->data.mutex);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->data.mutex);
	printf("philo %d is sleeping\n", philo->id);
	ft_usleep(philo->data.time_to_sleep);
	pthread_mutex_unlock(philo->data.mutex);
}

void	ft_start_routine(t_philo *philo)
{
	ft_eat(philo);
	ft_sleep(philo);
}
