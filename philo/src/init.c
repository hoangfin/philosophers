/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:27:18 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/10 18:42:05 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "philo.h"
#include "utils.h"

static int	init_philo(t_philo *philo, int i, t_app *app)
{
	philo->app = app;
	philo->id = i + 1;
	philo->thread = (pthread_t *)malloc(sizeof(pthread_t));
	if (philo->thread == NULL)
		return (-1);
	philo->start = now();
	philo->last_meal = now();
	if (philo->start == -1 || philo->last_meal == -1)
		return (-1);
	philo->left_fork = app->forks[i];
	philo->right_fork = app->forks[(i + 1) % app->number_of_forks];
	philo->state_mutex = malloc(sizeof(pthread_mutex_t));
	philo->meal_mutex = malloc(sizeof(pthread_mutex_t));
	if (
		philo->state_mutex == NULL
		|| philo->meal_mutex == NULL
		|| pthread_mutex_init(philo->state_mutex, NULL) != 0
		|| pthread_mutex_init(philo->meal_mutex, NULL) != 0
	)
		return (-1);
	return (0);
}

static int	create_philos(t_app *app)
{
	int		i;
	t_philo	*philo;

	app->philos = (t_philo *)malloc(app->number_of_philos * sizeof(t_philo));
	if (app->philos == NULL)
		return (write(2, "malloc: Can not allocate memory\n", 32), -1);
	memset(app->philos, 0, app->number_of_philos * sizeof(t_philo));
	i = 0;
	while (i < app->number_of_philos)
	{
		philo = app->philos + i;
		if (init_philo(philo, i, app) == -1)
			return (-1);
		i++;
	}
	return (0);
}

static int	create_forks(t_app *app)
{
	pthread_mutex_t	*fork;

	app->forks = (pthread_mutex_t **) malloc(
		app->number_of_philos * sizeof(pthread_mutex_t *)
	);
	if (app->forks == NULL)
		return (write(2, "malloc: Can not allocate memory\n", 32), 12);
	app->number_of_forks = 0;
	while (app->number_of_forks < app->number_of_philos)
	{
		fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (fork == NULL || pthread_mutex_init(fork, NULL) != 0)
			return (-1);
		app->forks[app->number_of_forks] = fork;
		app->number_of_forks++;
	}
	return (0);
}

int	init(t_app *app, char **argv)
{
	memset(app, 0, sizeof(t_app));
	app->number_of_philos = (int)ft_atol(argv[1], NULL);
	app->time_to_die = ft_atol(argv[2], NULL);
	app->time_to_eat = ft_atol(argv[3], NULL);
	app->time_to_sleep = ft_atol(argv[4], NULL);
	app->meal_limit = -1;
	if (argv[5] != NULL)
		app->meal_limit = (int)ft_atol(argv[5], NULL);
	app->sim_state_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	app->printer = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (
		app->sim_state_mutex == NULL
		|| app->printer == NULL
		|| pthread_mutex_init(app->sim_state_mutex, NULL) != 0
		|| pthread_mutex_init(app->printer, NULL) != 0
		|| create_forks(app) < 0
		|| create_philos(app) < 0
	)
		return (destroy(app), -1);
	return (0);
}
