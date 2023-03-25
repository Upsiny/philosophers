/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:58:57 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/25 15:48:56 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

struct	s_philo;

typedef struct s_data {
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long long int	time_start;
	int				is_alive;
	int				end_routine;
	pthread_t		tid[201];
	pthread_t		death;
	pthread_mutex_t	*for_death;
	pthread_mutex_t	straw[201];
	pthread_mutex_t	*mutex;
	struct s_philo	*philo[201];
}	t_data;

typedef struct s_philo {
	int				id;
	long long int	last_eat;
	t_data			*data;
}	t_philo;

int				ft_parse(int ac, char **av, t_data *data);
int				ft_check_death(t_philo *philo);
void			ft_start_routine(t_philo *philo);
void			*ft_death(void *dat);
int				ft_atoi(char *str);
long long int	ft_time(void);
void			ft_usleep(int i, t_data *data);
void			print_time(long long int start);
void			ft_print(char *msg, pthread_mutex_t *mutex,
					int id, t_philo *philo);

#endif
