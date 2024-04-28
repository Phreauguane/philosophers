/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:39:16 by jde-meo           #+#    #+#             */
/*   Updated: 2024/04/28 19:21:32 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	create_mutex(t_main *main)
{
	int	i;

	i = -1;
	pthread_mutex_init(&(main->write_l), NULL);
	pthread_mutex_init(&(main->meal_l), NULL);
	while (++i < main->amount)
		pthread_mutex_init(&(main->forks[i]), NULL);
}

void	launch(t_main *main)
{
	int	i;

	i = -1;
	create_mutex(main);
	main->start = get_time();
	while (++i < main->amount)
	{
		pthread_create(&(main->philos[i].thread), NULL,
			philo_work, (void *)&(main->philos[i]));
	}
	check_death(main);
	exit_main(main);
}

void	exit_main(t_main *main)
{
	int	i;

	i = -1;
	while (++i < main->amount)
		pthread_join(main->philos[i].thread, NULL);
	pthread_mutex_destroy(&(main->write_l));
	pthread_mutex_destroy(&(main->meal_l));
	i = -1;
	while (++i < main->amount)
		pthread_mutex_destroy(&(main->forks[i]));
}

void	check_death(t_main *main)
{
	int		i;

	while (!main->miam)
	{
		i = -1;
		sleep_ms(1, main);
		while (++i < main->amount && !main->dead)
		{
			if (get_time2(main) - main->philos[i].time_of_meal
				>= main->philos[i].to_die)
			{
				print_action(main, i, "died");
				main->dead = 1;
			}
		}
		if (main->dead)
			break ;
		i = -1;
		while (++i < main->amount
			&& main->philos[i].meals >= main->philos[i].max_meals)
			;
		if (i == main->amount)
			main->miam = 1;
	}
}
