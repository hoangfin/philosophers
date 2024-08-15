/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:10:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/15 19:53:58 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_BONUS_H
# define TYPES_BONUS_H

# define CREATION_TIME_PER_PROCESS_MS 10
# define DEATH_EXIT_CODE 42
# define FORKS_SEM "/forks_sem"
# define PRINTER_SEM "/printer_sem"

# include <semaphore.h>
# include <pthread.h>

struct	s_sim;

typedef struct s_philo
{
	struct s_sim	*sim;
	sem_t			*meal_sem;
	sem_t			*state_sem;
	int				id;
	pid_t			pid;
	int				meal_count;
	long			last_meal;
	long			next_meal;
	int				is_dead;
	int				has_enough_meal;
}	t_philo;

typedef enum e_sim_state
{
	SIM_RUNNING,
	SIM_END,
	SIM_END_BY_PHILO_DEATH
}	t_sim_state;

typedef struct s_sim
{
	t_philo	*philos;
	sem_t	*forks;
	sem_t	*printer_sem;
	char	sem_name_buf[256];
	int		number_of_philos;
	int		number_of_pids;
	int		meal_limit;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	start;
}	t_sim;

#endif
