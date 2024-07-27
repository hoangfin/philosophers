/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:27:18 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/27 20:48:29 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "philo.h"
#include "sim.h"
#include "utility.h"

static int	create_philos(t_sim *sim)
{
	int		i;
	t_philo	*philo;

	sim->philos = (t_philo *)malloc(sim->number_of_philos * sizeof(t_philo));
	if (sim->philos == NULL)
		return (write(2, "Error: create_philos: malloc\n", 29), -1);
	memset(sim->philos, 0, sim->number_of_philos * sizeof(t_philo));
	i = 0;
	while (i < sim->number_of_philos)
	{
		philo = sim->philos + i;
		if (init_philo(philo, i + 1, sim) == -1)
			return (-1);
		i++;
	}
	return (0);
}

static int	create_semaphores(t_sim *sim)
{
	sem_unlink(FORKS_SEM);
	sem_unlink(PRINTER_SEM);
	sem_close(sim->forks);
	sem_close(sim->printer);
	sim->forks = sem_open(FORKS_SEM, O_CREAT, 0600, sim->number_of_philos);
	sim->printer = sem_open(PRINTER_SEM, O_CREAT, 0600, 1);
	if (sim->forks == SEM_FAILED || sim->printer == SEM_FAILED)
		return (write(2, "Error: create_semaphores: sem_open\n", 35), -1);
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
	sim->state_mutex = malloc(sizeof(pthread_mutex_t));
	if (
		sim->state_mutex == NULL
		|| pthread_mutex_init(sim->state_mutex, NULL) != 0
		|| create_semaphores(sim) != 0
		|| create_philos(sim) != 0
	)
		return (destroy(sim), -1);
	return (0);
}
