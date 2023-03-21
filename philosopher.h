/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:58:57 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/21 11:51:08 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

struct s_philo;

typedef struct s_data {
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_t		tid[200];
	pthread_mutex_t	*fourchette;
	pthread_mutex_t	*mutex;
	struct s_philo	*philo[200];
}	t_data;

typedef struct	s_philo {
	int				id;
	t_data			*data;
}	t_philo;

/****************************************************************\
|							 PHILO								 |
\****************************************************************/

int		ft_parse(int ac, char **av, t_data *data);
void	ft_start_routine(t_philo *philo);

/****************************************************************\
|                            UTILS                               |
\****************************************************************/

int		ft_atoi(char *str);
void	ft_usleep(int i);

#endif
