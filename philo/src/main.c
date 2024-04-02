/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larz <larz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:15:17 by jde-meo           #+#    #+#             */
/*   Updated: 2024/04/02 14:38:25 by larz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	free_main(t_main *main)
{
	if (!main)
		return ;
	if (main->philos)
		free(main->philos);
	if (main->forks)
		free(main->forks);
}

int	main(int ac, char **av)
{
	t_main	main;

	init(ac, av, &main);
	launch(&main);
	free_main(&main);
}
