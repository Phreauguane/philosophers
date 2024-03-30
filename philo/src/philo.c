/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:53:43 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/30 15:17:12 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	free_philo(t_philo *philo)
{
	if (!philo)
		return ;
	(void)philo;
}

void	init_philo(int ac, char **av, t_philo *philo)
{
	if (!philo)
		return ;
	exit_error(check_input(ac, av), NULL);
	philo->thread_amt = ft_atoi(av[1]);
	philo->to_die = ft_atoi(av[2]);
	philo->to_eat = ft_atoi(av[3]);
	philo->to_slp = ft_atoi(av[4]);
	philo->meal_amt = ft_atoi(av[5]);
	if (philo->thread_amt < 1 || philo->thread_amt > MAX_PHILO)
		exit_error(ERR_TOO_MUCH_PHILO, NULL);
	if (philo->to_die < 0 || philo->to_die > MAX_DIE
		|| philo->to_eat < 0 || philo->to_eat > MAX_EAT
		|| philo->to_slp < 0 || philo->to_slp > MAX_SLP)
		exit_error(ERR_WRONG_TIMES, NULL);
}
