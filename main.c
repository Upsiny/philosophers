/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:55:40 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/13 16:41:07 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_thread_talk(t_data *data)
{
	(void)data;
	printf("bonjour, je suis un philosopher !\n");
	return (NULL);
}

void	ft_create_philo(t_data *data)
{
	int	i;

	i = 1;
	pthread_t	threadid[data->nb_philo];
	while (data->nb_philo >= i)
	{
		pthread_create(&threadid[i], NULL, ft_thread_talk, data);
		i++;
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
	ft_create_philo(data);
}
