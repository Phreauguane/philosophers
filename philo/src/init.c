/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 12:41:28 by jde-meo           #+#    #+#             */
/*   Updated: 2024/04/10 14:06:59 by jde-meo          ###   ########.fr       */
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

	i = 0;
	if (ac < 5 || ac > 6)
		return (ERR_WRONG_ARGS);
	while (av[++i])
		if (!check_arg(av[i]))
			return (ERR_WRONG_ARGS);
	return (0);
}

void	dup_data(t_worker *philo, t_main *main, t_init init, int i)
{
	clear_data(philo, sizeof(t_worker));
	philo->philos = init.philos;
	philo->to_die = init.to_die;
	philo->to_eat = init.to_eat;
	philo->to_sleep = init.to_slp;
	philo->max_meals = init.max_meals;
	philo->write_l = &(main->write_l);
	philo->meal_l = &(main->meal_l);
	philo->id = i;
}

void	create_philos(t_init init, t_main *main)
{
	int	i;

	i = -1;
	main->philos = malloc(sizeof(t_worker) * init.philos);
	main->amount = init.philos;
	main->forks = malloc(sizeof(pthread_mutex_t) * init.philos);
	while (++i < init.philos)
	{
		dup_data(&(main->philos[i]), main, init, i);
		main->philos[i].main = main;
		main->philos[i].fork1 = &(main->forks[i]);
		main->philos[i].fork2 = &(main->forks[(i + 1) % init.philos]);
	}
}

void	init(int ac, char **av, t_main *main)
{
	t_init	init;

	clear_data(main, sizeof(t_main));
	exit_error(check_input(ac, av), NULL);
	init.philos = (int)ft_atoi(av[1]);
	init.to_die = (int)ft_atoi(av[2]);
	init.to_eat = (int)ft_atoi(av[3]);
	init.to_slp = (int)ft_atoi(av[4]);
	init.max_meals = INT_MAX;
	if (ac == 6)
		init.max_meals = (int)ft_atoi(av[5]);
	if (init.philos > MAX_PHILO || init.philos < 1)
		exit_error(ERR_TOO_MUCH_PHILO, NULL);
	if (init.to_die > MAX_DIE
		|| init.to_eat > MAX_EAT
		|| init.to_slp > MAX_SLP)
		exit_error(ERR_WRONG_TIMES, NULL);
	create_philos(init, main);
}
