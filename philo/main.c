/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:02:38 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/24 23:42:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include "philo.h"

int	main(int argc, char **argv)
{
	t_app	app;

	if (validate(argc, argv) == 0)
		return (1);
	if (init(&app, argc, argv) == -1)
		return (1);
	
	return (0);
}
