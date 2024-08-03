/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:10:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/03 16:13:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_BONUS_H
# define TYPES_BONUS_H

# define CREATION_TIME_PER_PROCESS_MS 10
# define DEATH_EXIT_CODE 42
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
	int				meal_count;
	long			last_meal;
	long			next_meal;
}	t_philo;

typedef enum e_sim_state
{
	SIM_RUNNING,
	SIM_END,
	SIM_END_BY_PHILO_DEATH
}	t_sim_state;

typedef struct s_sim
{
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*printer_sem;
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
