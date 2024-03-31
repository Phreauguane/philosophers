/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:14:53 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/31 13:47:52 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

// VALUES
# define MAX_PHILO	200
# define MAX_DIE	20000
# define MAX_EAT	20000
# define MAX_SLP	20000

// ERROR CODES
# define ERR_WRONG_ARGS			1
# define ERR_WRONG_TIMES		2
# define ERR_TOO_MUCH_PHILO		3

typedef struct s_worker
{
	int				id;
	int				philos;
	int				meals;
	int				max_meals;
	char			is_eating;
	char			*dead;
	size_t			time_of_meal;
	size_t			to_die;
	size_t			to_eat;
	size_t			to_sleep;
	size_t			time_of_start;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	pthread_mutex_t	*write_l;
	pthread_mutex_t	*dead_l;
	pthread_mutex_t	*meal_l;
	pthread_t		thread;
}	t_worker;

typedef struct s_main
{
	t_worker		*observer;
	t_worker		*philos;
	int				amount;
	char			dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_l;
	pthread_mutex_t	meal_l;
	pthread_mutex_t	write_l;
}	t_main;

typedef struct s_init
{
	int				philos;
	int				max_meals;
	size_t			to_die;
	size_t			to_eat;
	size_t			to_slp;
}	t_init;

//		<MAIN.C>		//
void	free_main(t_main *main);

//		<ERROR.C>		//
void	exit_error(int error, t_main *main);

//		<UTILS.C>		//
size_t	ft_atoi(char *str);
void	clear_data(void	*data, size_t size);

//		<INIT.C>		//
void	init(int ac, char **av, t_main *main);

//		<TIME.C>		//
size_t	get_time(void);
int		sleep_ms(size_t ms);

#endif