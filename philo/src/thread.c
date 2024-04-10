/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:39:16 by jde-meo           #+#    #+#             */
/*   Updated: 2024/04/10 13:52:53 by jde-meo          ###   ########.fr       */
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
