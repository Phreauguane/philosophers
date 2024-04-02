/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larz <larz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:22:09 by larz              #+#    #+#             */
/*   Updated: 2024/04/02 14:50:18 by larz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	miam(t_worker *p)
{
	t_main		*main;

	main = p->main;
	pthread_mutex_lock(p->fork1);
	print_action(main, p->id, "has taken a fork");
	pthread_mutex_lock(p->fork2);
	print_action(main, p->id, "has taken a fork");
	pthread_mutex_lock(p->meal_l);
	print_action(main, p->id, "is eating");
	p->time_of_meal = get_time();
	pthread_mutex_unlock(p->meal_l);
	sleep_ms(p->to_eat, main);
	(p->meals)++;
	pthread_mutex_unlock(p->fork1);
	pthread_mutex_unlock(p->fork2);
}

void	*philo_work(void *void_p)
{
	t_worker	*p;
	t_main		*main;

	p = (t_worker *)void_p;
	main = p->main;
	if (p->id % 2)
		usleep(15000);
	while (!main->dead)
	{
		miam(p);
		if (main->miam)
			break ;
		print_action(main, p->id, "is sleeping");
		sleep_ms(p->to_sleep, main);
		print_action(main, p->id, "is thinking");
	}
	return (NULL);
}

void	print_action(t_main *main, int i, char *action)
{
	pthread_mutex_lock(&(main->write_l));
	if (!main->dead)
		printf("%-6lu %d %s\n", get_time() - main->time_of_start,
			i, action);
	pthread_mutex_unlock(&(main->write_l));
}

void	check_death(t_main *main)
{
	int	i;

	while (!main->miam)
	{
		i = -1;
		while (++i < main->amount && !main->dead)
		{
			if (get_time() - main->philos[i].time_of_meal
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
