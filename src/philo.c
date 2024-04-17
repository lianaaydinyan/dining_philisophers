/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:41:42 by liaydiny          #+#    #+#             */
/*   Updated: 2024/01/08 17:41:45 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_usleep(int milliseconds, t_data *data)
{
	int	start;

	start = get_current_time2();
	while (get_current_time2() - start < milliseconds
		&& is_dead_or_not(data))
		usleep(milliseconds / 10);
	return (0);
}

int	get_current_time2(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		perror("gettimeofday() error\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (-1);
	if (!parsing(ac, av))
		return (-1);
	else
	{
		if (!(give_the_args(ac, av, data)))
			return (-1);
		else
		{
			if (create_threads(data) == -1)
				return (-1);
		}
	}
	return (0);
}
