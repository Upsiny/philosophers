/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:55:40 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/21 11:58:45 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo	*ft_new_philo(t_data *data, int i)
{
	t_philo			*philo;

	philo = malloc(sizeof(t_philo));

	philo->id = i;
	data->philo[i] = philo;
	philo->data = data;
	printf("created philo\n");
	return (philo);
}

void	*ft_new_thread(void* philo)
{
	ft_start_routine(philo);
	return (NULL);
}

void	ft_create_philos(t_data *data)
{
	int	i;

	i = 1;
	while (data->nb_philo >= i)
	{
		data->philo[i] = ft_new_philo(data, i);
		pthread_create(&data->tid[i], NULL, ft_new_thread, data->philo[i]);
		i++;
	}
	while (i >= 0)
	{
		pthread_join(data->tid[i], NULL);
		i--;
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	t_data	data;

	data.mutex = malloc(sizeof(pthread_mutex_t));
	if (ft_parse(ac, av, &data) != 1)
		return (0);
	ft_create_philos(&data);
}
