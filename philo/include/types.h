/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:00:20 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/09 00:50:27 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define ERROR_MUTEX_LOCK "Error: pthread_mutex_lock\n"

# include <pthread.h>

struct	s_app;

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef enum e_philo_state
{
	THINKING,
	TAKE_A_FORK,
	EATING,
	SLEEPING,
	DIED
}	t_philo_state;

typedef enum e_sim_state
{
	SIM_RUNNING,
	SIM_END,
	SIM_ERROR
}	t_sim_state;

typedef struct s_philo
{
	struct s_app	*app;
	pthread_t		*thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*state_mutex;
	pthread_mutex_t	*meal_mutex;
	int				id;
	int				meal_eaten;
	long			last_meal;
	long			start;
	t_philo_state	state;
}	t_philo;

typedef struct s_app
{
	t_philo			*philos;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*sim_state_mutex;
	pthread_mutex_t	*printer;
	int				number_of_philos;
	int				number_of_threads;
	int				number_of_forks;
	int				meal_limit;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_start;
	t_sim_state		sim_state;
}	t_app;

#endif
