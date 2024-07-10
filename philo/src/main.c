/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:02:38 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/06 20:29:11 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_app	app;
	int		status;
	int		wstatus;

	if (validate(argc, argv) == 0)
		return (EXIT_FAILURE);
	if (init(&app, argv) == -1)
		return (EXIT_FAILURE);
	status = start(&app);
	wstatus = wait(&app);
	destroy(&app);
	if (status < 0 || wstatus < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
