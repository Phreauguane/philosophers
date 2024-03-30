/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:52:38 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/30 15:20:22 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	exit_error(int error, t_philo *philo)
{
	if (error == ERR_WRONG_ARGS)
		printf("philosophers: wrong arguments: please use :\n \t\'./philosophers <philo_amount> \
		<time_to_die> <time_to_eat> <time_to_sleep> [meal_amount]\'\n");
	else if (error == ERR_WRONG_TIMES)
		printf("philosophers: wrong times: \n\
		\ttime to die : 0 to %d\n\
		\ttime to eat : 0 to %d\n\
		\ttime to sleep : 0 to %d\n",
			MAX_DIE, MAX_EAT, MAX_SLP);
	else if (error == ERR_TOO_MUCH_PHILO)
		printf("philosophers: too much philosophers: \
		use number between 1 and %d\n", MAX_PHILO);
	else
		return ;
	free_philo(philo);
	exit(error);
}
