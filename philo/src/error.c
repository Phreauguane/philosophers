/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:52:38 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/31 13:36:15 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	exit_error(int error, t_main *main)
{
	if (error == ERR_WRONG_ARGS)
		printf("philosophers: wrong arguments: please use :\n \'./philosophers <philo_amount> \
<time_to_die> <time_to_eat> <time_to_sleep> [meal_amount]\'\n");
	else if (error == ERR_WRONG_TIMES)
		printf("philosophers: wrong times: please use\n\
\t%-15s : 0 to %d\n\
\t%-15s : 0 to %d\n\
\t%-15s : 0 to %d\n",
			"time to die", MAX_DIE,
			"time to eat", MAX_EAT,
			"time to sleep", MAX_SLP);
	else if (error == ERR_TOO_MUCH_PHILO)
		printf("philosophers: too much philosophers: \
use number between 1 and %d\n", MAX_PHILO);
	else
		return ;
	(void)main;
	exit(error);
}
