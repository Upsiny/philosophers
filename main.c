/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:55:40 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/17 16:33:51 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_new_philo(t_data *data, int i)
{
	t_philo			*philo;

	philo = malloc(sizeof(t_philo));

	philo->id = i;
	data->philo[i] = philo;
	printf("philo creer\n");
}

void	*ft_new_thread(void* raw_data)
{
	t_data	*data;

	data = raw_data;
	printf("bonjour, je suis un philosopher !\n");
	return (NULL);
}

void	ft_create_philos(t_data *data)
{
	int	i;

	i = 1;
	while (data->nb_philo >= i)
	{
		ft_new_philo(data, i);
//		pthread_create(&data->tid[i], NULL, ft_new_thread, data);
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
	t_data	*data;

	data = malloc(sizeof(data));
	data->nb_philo = ft_atoi(av[1]);
//	data->time_to_die = ft_atoi(av[2]);
//	data->time_to_eat = ft_atoi(av[3]);
//	data->time_to_sleep = ft_atoi(av[4]);
	ft_create_philos(data);
}
