/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:09:31 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/31 13:25:03 by jde-meo          ###   ########.fr       */
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
