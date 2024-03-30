/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:14:53 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/30 15:16:01 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

// VALUES
# define MAX_PHILO	200
# define MAX_DIE	20000
# define MAX_EAT	20000
# define MAX_SLP	20000

// ERROR CODES
# define ERR_WRONG_ARGS			1
# define ERR_WRONG_TIMES		2
# define ERR_TOO_MUCH_PHILO		3

typedef struct s_philo
{
	pthread_t	*threads;
	int			thread_amt;
	int			meal_amt;
	int			to_die;
	int			to_eat;
	int			to_slp;
}	t_philo;

//		PHILO.C		//
void	free_philo(t_philo *philo);
void	init_philo(int ac, char **av, t_philo *philo);

//		ERROR.C		//
void	exit_error(int error, t_philo *philo);

//		UTILS.C		//
int		ft_atoi(char *nptr);

#endif