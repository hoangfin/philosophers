/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:11:54 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/25 00:15:41 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ERR_INV_ARG_COUNT "Error: Invalid Argument. Requires 4 arguments (or 5)\n"

typedef struct s_app
{
	// pthread_t	**philosophers;
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
}	t_app;

typedef enum e_philo_state
{
	EATING,
	THINKING,
	SLEEPING
}	t_philo_state;

typedef enum e_fork_state
{
	AVAILABLE,
	OCCUPIED
}	t_fork_state;

typedef struct s_philo
{
	int				id;
	t_philo_state	state;
}	t_philo;

int	validate(int argc, char **argv);

#endif