/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:39:37 by jde-meo           #+#    #+#             */
/*   Updated: 2024/04/03 17:33:02 by jde-meo          ###   ########.fr       */
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

size_t	get_time_us(void)
{
	struct timeval	time;
	size_t			t;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	t = time.tv_sec * 1000000 + time.tv_usec;
	return (t);
}

int	sleep_ms(size_t ms, t_main *main)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms && !main->dead && !main->miam)
		usleep(ms / 10);
	return (0);
}
