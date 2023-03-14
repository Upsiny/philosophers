/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:55:40 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/14 17:03:17 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_philo(void* raw_data)
{
	t_data	*data;

	data = raw_data;
	printf("bonjour, je suis un philosopher !\n");
	while (1) {
		printf ("je suis philo idiot numeros %d\n", );
		sleep(1);
	}
	return (NULL);
}

void	ft_create_philos(t_data *data)
{
	int	i;

	i = 1;
	pthread_t	tid[data->nb_philo];
	while (data->nb_philo >= i)
	{
		pthread_create(&tid[i], NULL, ft_philo, data);
		pthread_join(tid[i], NULL); // utiliser un mutex;
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
	ft_create_philos(data);
}
