/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:30:40 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/21 11:58:41 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->data->mutex);
	printf("philo %d is eating\n", philo->id);
	pthread_mutex_unlock(philo->data->mutex);
	ft_usleep(philo->data->time_to_eat);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->data->mutex);
	printf("philo %d is sleeping\n", philo->id);
	pthread_mutex_unlock(philo->data->mutex);
	ft_usleep(philo->data->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(philo->data->mutex);
	printf("philo %d is thinking\n", philo->id);
	pthread_mutex_unlock(philo->data->mutex);
}
/*
int		ft_death()
{
	
}
*/
void	ft_start_routine(t_philo *philo)
{
	int	i;

	i = 1;
	while (philo->data->must_eat >= i)
	{
		printf("-------------\n");
		printf("[%d] ", gettimeofday(tv, dst_met));
		printf("for %d x time, ", i);
		ft_think(philo);
		printf("[%d] ", gettimeofday(tv, dst_met));
		printf("for %d x time, ", i);
		ft_eat(philo);
		printf("[%d] ", gettimeofday(tv, dst_met));
		printf("for %d x time, ", i);
		ft_sleep(philo);
		i++;
	}
}
