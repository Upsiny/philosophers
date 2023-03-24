/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:44:00 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/24 11:52:57 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_death(void *dat)
{
	t_data *data;
	int				i;
	long long int	time_death;
	long long int	current_time;
	struct timeval	time;

	data = (t_data *) dat;
	i = 1;
	gettimeofday(&time, NULL);
	while (i <= data->nb_philo)
	{
		pthread_mutex_lock(&data->for_death);
		time_death = data->philo[i]->last_eat + data->time_to_die;
		current_time = time.tv_sec * 1000 + time.tv_usec / 1000;
		if (time_death < current_time)
		{
			data->is_alive = 0;
			ft_print("is dead", &data->for_death, i, data->philo[i]);
			break ;
		}		
		pthread_mutex_unlock(&data->for_death);
		i++;
	}
	printf("death is watching you !\n");
	return (NULL);
}
