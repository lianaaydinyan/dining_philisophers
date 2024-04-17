/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:42:09 by liaydiny          #+#    #+#             */
/*   Updated: 2024/01/08 17:42:12 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eaten_helper(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->global_data->died_mtx);
	philo->global_data->dead_flag = 1;
	pthread_mutex_unlock(&philo->global_data->died_mtx);
	while (i < philo->global_data->num_of_philos)
	{
		pthread_join(philo->global_data->thread_id[i], NULL);
		i++;
	}
}

int	eaten(t_philo *philo)
{
	int	count;

	pthread_mutex_lock(&philo->global_data->_eat);
	count = philo->eat_count;
	pthread_mutex_unlock(&philo->global_data->_eat);
	pthread_mutex_lock(&philo->global_data->_fini);
	if (philo->global_data->def_all_eat == count && philo->eaty != 'y')
	{
		philo->eaty = 'y';
		pthread_mutex_lock(&philo->global_data->_fin);
		philo->global_data->already_eaty++;
		pthread_mutex_unlock(&philo->global_data->_fin);
	}
	pthread_mutex_unlock(&philo->global_data->_fini);
	if (philo->global_data->num_of_philos == philo->global_data->already_eaty)
	{
		eaten_helper(philo);
		return (0);
	}
	return (1);
}

int	starving_check(t_philo *philo)
{
	int	i;
	int	count;

	i = 0;
	pthread_mutex_lock(&philo->global_data->last_eat);
	count = philo->last_meal;
	pthread_mutex_unlock(&philo->global_data->last_eat);
	if (get_current_time2() - count > philo->time_to_die)
	{
		pthread_mutex_lock(&philo->global_data->died_mtx);
		philo->global_data->dead_flag = 1;
		pthread_mutex_unlock(&philo->global_data->died_mtx);
		printf("%i ", get_current_time2() - philo->global_data->start_time);
		printf("%i died\n", philo->id);
		i = 0;
		while (i < philo->global_data->num_of_philos)
		{
			pthread_join(philo->global_data->thread_id[i], NULL);
			i++;
		}
		return (0);
	}
	else if (philo->global_data->def_all_eat != -1)
		return (eaten(philo));
	return (1);
}
