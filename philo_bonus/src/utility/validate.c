/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:24:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/07/17 17:35:10 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utility.h"

static int	has_not_a_number(char **argv)
{
	char	*temp;

	while (*argv != NULL)
	{
		temp = *argv;
		if (*temp == '\0')
			return (1);
		while (*temp != '\0')
		{
			if (*temp == '-' || *temp == '+')
			{
				if (*(temp + 1) == '\0' || temp != *argv)
					return (1);
			}
			if (
				!(*temp >= '0' && *temp <= '9')
				&& *temp != '-'
				&& *temp != '+'
			)
				return (1);
			temp++;
		}
		argv++;
	}
	return (0);
}

static int	has_invalid_number(char **argv)
{
	int		overflow;
	long	number;

	overflow = 0;
	while (*argv != NULL)
	{
		number = ft_atol(*argv, &overflow);
		if (overflow)
			return (write(2, "Error: Number out of range\n", 27), 1);
		if (number <= 0)
			return (write(2, "Error: Number must be > 0\n", 26), 1);
		argv++;
	}
	return (0);
}

int	validate(int argc, char **argv)
{
	(void)argv;
	if (argc < 5 || argc > 6)
		return (write(2, "Error: Invalid number of arguments\n", 35), 0);
	if (has_not_a_number(argv))
		return (write(2, "Error: Not a number\n", 20), 0);
	if (has_invalid_number(argv))
		return (0);
	return (1);
}
