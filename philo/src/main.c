/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:15:17 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/31 13:36:20 by jde-meo          ###   ########.fr       */
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
}
