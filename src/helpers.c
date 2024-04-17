/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:40:56 by liaydiny          #+#    #+#             */
/*   Updated: 2024/01/08 17:40:57 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	have_to_be_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(_isdigit(str[i])))
		{
			printf("Please enter numeric arguments\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	fill_the_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data)->num_of_philos)
	{
		if (i == 0)
			data->philos[i].left_fork = (data)->num_of_philos - 1;
		else
			data->philos[i].left_fork = i - 1;
		data->philos[i].rigth_fork = i;
		i++;
	}
}

int	is_dead_or_not(t_data *data)
{
	pthread_mutex_lock(&data->died_mtx);
	if (data->dead_flag)
	{
		pthread_mutex_unlock(&data->died_mtx);
		return (0);
	}
	pthread_mutex_unlock(&data->died_mtx);
	return (1);
}
