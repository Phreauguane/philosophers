/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:15:17 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/30 15:14:12 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_arg(char *arg)
{
	if (arg == NULL)
		return (0);
	while (*arg >= '0' && *arg <= '9')
		arg++;
	if (*arg == '\0')
		return (1);
	return (0);
}

int	check_input(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac < 5 || ac > 6)
		return (ERR_WRONG_ARGS);
	while (av[++i])
		if (!check_arg(av[i]))
			return (ERR_WRONG_ARGS);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	init_philo(ac, av, &philo);
	free_philo(&philo);
	return (0);
}