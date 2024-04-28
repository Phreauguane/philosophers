/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:22:09 by larz              #+#    #+#             */
/*   Updated: 2024/04/28 19:21:26 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	miam(t_worker *p)
{
	t_main		*main;

	main = p->main;
	pthread_mutex_lock(p->fork1);
	if (p->main->dead)
		return ;
	print_action(main, p->id, "has taken a fork");
	pthread_mutex_lock(p->fork2);
	p->time_of_meal = get_time2(main);
	if (p->main->dead)
		return ;
	print_action(main, p->id, "has taken a fork");
	(p->meals)++;
	if (p->main->dead)
		return ;
	print_action(main, p->id, "is eating");
	sleep_ms_from(p->time_of_meal, p->to_eat, main);
	pthread_mutex_unlock(p->fork1);
	pthread_mutex_unlock(p->fork2);
}

void	zzzz(t_worker *p)
{
	size_t		t;

	if (p->main->dead)
		return ;
	t = p->time_of_meal + p->to_eat;
	print_action(p->main, p->id, "is sleeping");
	sleep_ms_from(t, p->to_sleep, p->main);
}

void	hmmm(t_worker *p)
{
	if (p->main->dead)
		return ;
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
		sleep_ms(p->to_eat / 2, main);
	while (!main->dead && !main->miam)
	{
		miam(p);
		zzzz(p);
		hmmm(p);
	}
	return (NULL);
}
