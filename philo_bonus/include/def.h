/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:10:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/26 17:40:35 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H

# define FORKS_SEM "/forks_semaphore"
# define PRINTER_SEM "/printer_semaphore"

# include <semaphore.h>
# include <pthread.h>

struct	s_sim;

typedef struct s_philo
{
	struct s_sim	*sim;
	pthread_mutex_t	*meal_mutex;
	int				id;
	pid_t			pid;
	int				meal_eaten;
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
	sem_t			*forks;
	sem_t			*printer;
	pthread_mutex_t	*state_mutex;
	int				number_of_philos;
	int				number_of_pids;
	int				meal_limit;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start;
	t_sim_state		state;
}	t_sim;

#endif
