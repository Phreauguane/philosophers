/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larz <larz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:22:09 by larz              #+#    #+#             */
/*   Updated: 2024/04/11 15:04:17 by larz             ###   ########.fr       */
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
	p->time_of_meal = get_time2(main);
	print_action(main, p->id, "is eating");
	(p->meals)++;
	pthread_mutex_unlock(p->meal_l);
	sleep_ms_from(p->time_of_meal, p->to_eat, main);
	pthread_mutex_unlock(p->fork1);
	pthread_mutex_unlock(p->fork2);
}

void	zzzz(t_worker *p)
{
	size_t		t;

	t = get_time2(p->main);
	print_action(p->main, p->id, "is sleeping");
	sleep_ms_from(t, p->to_sleep, p->main);
}

void	hmmm(t_worker *p)
{
	print_action(p->main, p->id, "is thinking");
}

void	*philo_work(void *void_p)
{
	t_worker	*p;
	t_main		*main;

	p = (t_worker *)void_p;
	main = p->main;
	if (p->id % 2)
		sleep_ms(p->to_eat + 1, main);
	while (!main->dead && !main->miam)
	{
		miam(p);
		zzzz(p);
		hmmm(p);
	}
	return (NULL);
}

void	check_death(t_main *main)
{
	int		i;

	while (!main->miam)
	{
		i = -1;
		while (++i < main->amount && !main->dead)
		{
			pthread_mutex_lock(&(main->meal_l));
			if (get_time2(main) - main->philos[i].time_of_meal
				>= main->philos[i].to_die)
			{
				print_action(main, i, "died");
				main->dead = 1;
			}
			pthread_mutex_unlock(&(main->meal_l));
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
