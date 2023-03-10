/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:55:40 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/10 11:44:58 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_thread_talk(void *vargp)
{
	(void)vargp;
	printf("bonjour, je suis un philosopher !\n");
	return (NULL);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int	i;
	int	j;

	i = 2;
	pthread_t	thread_id[i];
	j = 0;
	while (i > 0)
	{
		pthread_create(&thread_id[j], NULL, ft_thread_talk, NULL);
		i--;
		j++;
	}
//	pthread_join(thread_id, NULL);
}
