/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:27:18 by hoatran           #+#    #+#             */
/*   Updated: 2024/08/16 20:46:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "sim_bonus.h"
#include "utils_bonus.h"

static int	init_philo(t_philo *philo, int id, t_sim *sim)
{
	philo->sim = sim;
	philo->id = id;
	set_name(sim->buffer, "/state_sem_", id);
	sem_unlink(sim->buffer);
	philo->state_sem = sem_open(sim->buffer, O_CREAT, 0600, 1);
	set_name(sim->buffer, "/meal_sem_", id);
	sem_unlink(sim->buffer);
	philo->meal_sem = sem_open(sim->buffer, O_CREAT, 0600, 1);
	if (philo->state_sem == SEM_FAILED || philo->meal_sem == SEM_FAILED)
	{
		write(STDERR_FILENO, "init_philo: sem_open\n", 21);
		return (-1);
	}
	return (0);
}

static int	create_philos(t_sim *sim)
{
	int		i;
	t_philo	*philo;

	i = 0;
	sim->philos = (t_philo *)malloc(sim->number_of_philos * sizeof(t_philo));
	if (sim->philos == NULL)
	{
		write(STDERR_FILENO, "create_philos: malloc\n", 22);
		return (-1);
	}
	memset(sim->philos, 0, sim->number_of_philos * sizeof(t_philo));
	while (i < sim->number_of_philos)
	{
		philo = sim->philos + i;
		if (init_philo(philo, i + 1, sim) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	init(t_sim *sim, char **argv)
{
	memset(sim, 0, sizeof(t_sim));
	sim->number_of_philos = (int)ft_atol(argv[0], NULL);
	sim->time_to_die = ft_atol(argv[1], NULL);
	sim->time_to_eat = ft_atol(argv[2], NULL);
	sim->time_to_sleep = ft_atol(argv[3], NULL);
	sim->meal_limit = -1;
	if (argv[4] != NULL)
		sim->meal_limit = (int)ft_atol(argv[4], NULL);
	sem_unlink(FORKS_SEM);
	sem_unlink(PRINTER_SEM);
	sim->forks = sem_open(FORKS_SEM, O_CREAT, 0600, sim->number_of_philos);
	sim->printer_sem = sem_open(PRINTER_SEM, O_CREAT, 0600, 1);
	if (
		sim->forks == SEM_FAILED
		|| sim->printer_sem == SEM_FAILED
		|| create_philos(sim) != 0
	)
	{
		destroy(sim);
		return (-1);
	}
	return (0);
}
