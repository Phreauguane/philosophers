/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:09:31 by jde-meo           #+#    #+#             */
/*   Updated: 2024/04/28 19:21:37 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	clear_data(void	*data, size_t size)
{
	char	*d;
	size_t	i;

	i = 0;
	d = (char *)data;
	while (i < size)
		d[i++] = 0;
}

char	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

void	print_action(t_main *main, int i, char *action)
{
	pthread_mutex_lock(&(main->write_l));
	if (!main->dead)
		printf("%lu %d %s\n", get_time2(main),
			i + 1, action);
	pthread_mutex_unlock(&(main->write_l));
}

void	print_action_time(t_main *main, int i, size_t time, char *action)
{
	if (!main->dead)
		printf("%lu %d %s\n", time, i + 1, action);
}

size_t	ft_atoi(char *str)
{
	size_t	s;
	size_t	n;

	s = 1;
	n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += (*str - '0');
		str++;
	}
	return (n * s);
}
