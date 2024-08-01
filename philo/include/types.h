/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:10:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/01 01:33:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <pthread.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

struct	s_sim;

typedef struct s_philo
{
	struct s_sim	*sim;
	pthread_t		*thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*meal_mutex;
	int				id;
	int				meal_count;
	long			last_meal;
	long			next_meal;
}	t_philo;

typedef enum e_sim_state
{
	SIM_RUNNING,
	SIM_END,
	SIM_ERROR
}	t_sim_state;

typedef struct s_sim
{
	t_philo			*philos;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*state_mutex;
	pthread_mutex_t	*printer_mutex;
	pthread_t		*monitor_thread;
	int				number_of_philos;
	int				number_of_threads;
	int				number_of_forks;
	int				meal_limit;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start;
	t_sim_state		state;
}	t_sim;

#endif
