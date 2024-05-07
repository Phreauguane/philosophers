/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larz <larz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:22:09 by larz              #+#    #+#             */
/*   Updated: 2024/05/07 13:25:30 by larz             ###   ########.fr       */
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
	p->time_of_meal = get_time2(main);
	(p->meals)++;
	print_action(main, p->id, "is eating");
	sleep_ms(p->to_eat, main);
	print_action(main, p->id, "j'ai fini mon boulot");
	pthread_mutex_unlock(p->fork1);
	print_action(main, p->id, "drop 1");
	pthread_mutex_unlock(p->fork2);
	print_action(main, p->id, "drop 2");
}

void	zzzz(t_worker *p)
{
	print_action(p->main, p->id, "is sleeping");
	sleep_ms(p->to_sleep, p->main);
}

void	hmmm(t_worker *p)
{
	print_action(p->main, p->id, "is thinking");
}

void	die(t_worker *p)
{
	pthread_mutex_lock(p->fork1);
	print_action(p->main, p->id, "has taken a fork");
	sleep_ms(p->to_die, p->main);
}

void	*philo_work(void *void_p)
{
	t_worker	*p;
	t_main		*main;

	p = (t_worker *)void_p;
	main = p->main;
	if (p->philos == 1)
		return (die(p), NULL);
	if (p->id % 2)
		sleep_ms(p->to_eat, main);
	while (!main->dead && !main->miam)
	{
		miam(p);
		zzzz(p);
		hmmm(p);
	}
	return (NULL);
}
