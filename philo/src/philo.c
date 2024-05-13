/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larz <larz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:22:09 by larz              #+#    #+#             */
/*   Updated: 2024/05/13 13:32:42 by larz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_eat(t_worker *p)
{
	t_main		*main;

	main = p->main;
	pthread_mutex_lock(p->fork1);
	print_action(main, p->id, "has taken a fork");
	pthread_mutex_lock(p->fork2);
	print_action(main, p->id, "has taken a fork");
	pthread_mutex_lock(p->write_l);
	p->time_of_meal = get_time2(main);
	pthread_mutex_unlock(p->write_l);
	print_action(main, p->id, "is eating");
	sleep_ms(p->to_eat, main);
	pthread_mutex_lock(p->write_l);
	(p->meals)++;
	pthread_mutex_unlock(p->write_l);
	pthread_mutex_unlock(p->fork1);
	pthread_mutex_unlock(p->fork2);
}

void	philo_sleep(t_worker *p)
{
	print_action(p->main, p->id, "is sleeping");
	sleep_ms(p->to_sleep, p->main);
}

void	philo_think(t_worker *p)
{
	print_action(p->main, p->id, "is thinking");
}

void	philo_die(t_worker *p)
{
	pthread_mutex_lock(p->fork1);
	print_action(p->main, p->id, "has taken a fork");
	sleep_ms(p->to_die, p->main);
	pthread_mutex_unlock(p->fork1);
}

void	*philo_work(void *void_p)
{
	t_worker	*p;
	t_main		*main;

	p = (t_worker *)void_p;
	main = p->main;
	if (p->philos == 1)
		return (philo_die(p), NULL);
	if (p->id % 2)
		sleep_ms(p->to_eat, main);
	while (1)
	{
		pthread_mutex_lock(&(main->write_l));
		if (main->dead)
		{
			print_action(main, p->id, "exit");
			pthread_mutex_unlock(&(main->write_l));
			return (NULL);
		}
		pthread_mutex_unlock(&(main->write_l));
		philo_eat(p);
		philo_sleep(p);
		philo_think(p);
	}
	return (NULL);
}
