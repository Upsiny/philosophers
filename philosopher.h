/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <hguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:58:57 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/13 13:53:01 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data {
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_data;

/****************************************************************\
|                            UTILS                               |
\****************************************************************/

int	ft_atoi(char *str);

#endif
