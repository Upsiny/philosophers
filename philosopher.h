/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:58:57 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/17 16:33:56 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

struct s_philo;

typedef struct s_data {
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_t		tid[200];
	struct s_philo	*philo[200];
}	t_data;

typedef struct	s_philo {
	pthread_mutex_t	fourchette;
	int				id;
	t_data			data;
}	t_philo;

/****************************************************************\
|							 PHILO								 |
\****************************************************************/

void	ft_start_routine(t_philo philo);

/****************************************************************\
|                            UTILS                               |
\****************************************************************/

int	ft_atoi(char *str);

#endif
