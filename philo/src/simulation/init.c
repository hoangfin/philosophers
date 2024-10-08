/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:27:18 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/03 00:43:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sim.h"
#include "utils.h"

static int	init_philo(t_philo *philo, int id, t_sim *sim)
{
	philo->sim = sim;
	philo->id = id;
	philo->thread = (pthread_t *)malloc(sizeof(pthread_t));
	if (philo->thread == NULL)
		return (-1);
	if (philo->id % 2 == 1)
	{
		philo->left_fork = sim->forks[id - 1];
		philo->right_fork = sim->forks[id % sim->number_of_forks];
	}
	else
	{
		philo->left_fork = sim->forks[id % sim->number_of_forks];
		philo->right_fork = sim->forks[id - 1];
	}
	philo->meal_mutex = malloc(sizeof(pthread_mutex_t));
	if (philo->meal_mutex == NULL)
		return (-1);
	if (pthread_mutex_init(philo->meal_mutex, NULL) != 0)
		return (-1);
	return (0);
}

static int	create_philos(t_sim *sim)
{
	int				i;
	t_philo			*philo;

	sim->philos = (t_philo *)malloc(sim->number_of_philos * sizeof(t_philo));
	if (sim->philos == NULL)
		return (write(2, "create_philos: malloc: sim->philos\n", 35), -1);
	memset(sim->philos, 0, sim->number_of_philos * sizeof(t_philo));
	i = 0;
	while (i < sim->number_of_philos)
	{
		philo = sim->philos + i;
		if (init_philo(philo, i + 1, sim) != 0)
			return (-1);
		i++;
	}
	return (0);
}

static int	create_forks(t_sim *sim)
{
	pthread_mutex_t	*fork;

	sim->forks = malloc(sim->number_of_philos * sizeof(pthread_mutex_t *));
	if (sim->forks == NULL)
		return (write(2, "create_forks: malloc: sim->forks\n", 33), -1);
	sim->number_of_forks = 0;
	while (sim->number_of_forks < sim->number_of_philos)
	{
		fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (fork == NULL)
			return (-1);
		if (pthread_mutex_init(fork, NULL) != 0)
			return (free(fork), -1);
		sim->forks[sim->number_of_forks] = fork;
		sim->number_of_forks++;
	}
	return (0);
}

int	init(t_sim *sim, char **argv)
{
	memset(sim, 0, sizeof(t_sim));
	sim->number_of_philos = (int)ft_atol(argv[1], NULL);
	sim->time_to_die = ft_atol(argv[2], NULL);
	sim->time_to_eat = ft_atol(argv[3], NULL);
	sim->time_to_sleep = ft_atol(argv[4], NULL);
	sim->meal_limit = -1;
	if (argv[5] != NULL)
		sim->meal_limit = (int)ft_atol(argv[5], NULL);
	sim->monitor_thread = malloc(sizeof(pthread_t));
	sim->state_mutex = malloc(sizeof(pthread_mutex_t));
	sim->printer_mutex = malloc(sizeof(pthread_mutex_t));
	if (
		sim->monitor_thread == NULL
		|| sim->state_mutex == NULL
		|| sim->printer_mutex == NULL
		|| pthread_mutex_init(sim->state_mutex, NULL) != 0
		|| pthread_mutex_init(sim->printer_mutex, NULL) != 0
		|| create_forks(sim) < 0
		|| create_philos(sim) < 0
	)
		return (destroy(sim), -1);
	return (0);
}
