/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:18:26 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/25 19:29:58 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_print(char *msg, pthread_mutex_t *mutex, int id, t_philo *philo)
{
	if (!ft_check_death(philo))
	{
		pthread_mutex_lock(mutex);
		print_time(philo->data->time_start);
		printf("%d %s\n", id, msg);
		pthread_mutex_unlock(mutex);
	}
	else
		return ;
}
