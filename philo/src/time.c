/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larz <larz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:39:37 by jde-meo           #+#    #+#             */
/*   Updated: 2024/05/15 12:04:26 by larz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t	get_time(void)
{
	struct timeval	time;
	size_t			t;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (t);
}

size_t	get_time2(t_main *main)
{
	struct timeval	time;
	size_t			t;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (t - main->start);
}

int	sleep_ms(size_t ms, t_main *main)
{
	size_t	start;
	(void)main;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(ms / 10);
	return (0);
}
