/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:44:00 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/28 15:42:08 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->data->for_death);
	if (philo->data->is_alive == 0)
	{
		pthread_mutex_unlock(philo->data->for_death);
		return (1);
	}
	pthread_mutex_unlock(philo->data->for_death);
	return (0);
}

int	ft_diff(t_data *data)
{
	pthread_mutex_lock(data->for_death);
	if (data->end_routine != data->nb_philo)
	{
		pthread_mutex_unlock(data->for_death);
		return (1);
	}
	pthread_mutex_unlock(data->for_death);
	return (0);
}

void	*ac_alive(t_data *data, int i)
{
	pthread_mutex_unlock(data->for_death);
	ft_print("died", data->mutex, i, data->philo[i]);
	pthread_mutex_lock(data->for_death);
	data->is_alive = 0;
	pthread_mutex_unlock(data->for_death);
	return (NULL);
}

void	*ft_death(void *dat)
{
	t_data			*data;
	int				i;
	long long int	time_death;
	long long int	current_time;
	struct timeval	time;

	data = (t_data *) dat;
	i = 1;
	while (ft_diff(data) != 0)
	{
		if (i > data->nb_philo)
			i = 1;
		pthread_mutex_lock(data->for_death);
		gettimeofday(&time, NULL);
		time_death = data->philo[i]->last_eat + data->time_to_die;
		current_time = time.tv_sec * 1000 + time.tv_usec / 1000;
		if (time_death < current_time)
			return (ac_alive(data, i));
		pthread_mutex_unlock(data->for_death);
		i++;
	}
	return (NULL);
}
