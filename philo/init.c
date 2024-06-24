/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:27:18 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/25 00:17:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "philo.h"
#include "utils.h"

int	init(t_app *app, int argc, char **argv)
{
	app->number_of_philosophers = ft_atoi(argv[1], NULL);
	app->time_to_die = ft_atoi(argv[2], NULL);
	app->time_to_eat = ft_atoi(argv[3], NULL);
	app->time_to_sleep = ft_atoi(argv[4], NULL);
	app->number_of_times_each_philosopher_must_eat = 0;
	if (argv[5] != NULL)
		app->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5], NULL);
}
