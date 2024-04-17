/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treadHelpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:41:52 by liaydiny          #+#    #+#             */
/*   Updated: 2024/01/08 17:41:55 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_routine(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forkk[philo->left_fork]);
	philo_printf(data, "has taken a fork\n", philo->id);
	pthread_mutex_lock(&data->forkk[philo->rigth_fork]);
	philo_printf(data, "has taken a fork\n", philo->id);
	philo_printf(data, "is eating\n", philo->id);
	ft_usleep(data->philos->time_to_eat, data);
	pthread_mutex_lock(&data->last_eat);
	philo->last_meal = get_current_time2();
	pthread_mutex_unlock(&data->last_eat);
	pthread_mutex_unlock(&data->forkk[philo->left_fork]);
	pthread_mutex_unlock(&data->forkk[philo->rigth_fork]);
	philo_printf(data, "is sleeping\n", philo->id);
	ft_usleep(data->philos->time_to_sleep, data);
	philo_printf(data, "is thinking\n", philo->id);
}

void	*thread_function(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->global_data;
	if (philo->id % 2)
		usleep(data->philos->time_to_eat / 2);
	while (is_dead_or_not(data))
	{
		philo_routine(philo, data);
		pthread_mutex_lock(&data->_eat);
		philo->eat_count += 1;
		pthread_mutex_unlock(&data->_eat);
		usleep(20);
	}
	return (NULL);
}

void	destroy_and_detach(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
		pthread_mutex_destroy(&data->forkk[i]);
	pthread_mutex_destroy(&data->print);
}

int	create_threads(t_data *data)
{
	int		i;
	t_philo	*arg;

	i = -1;
	data->start_time = get_current_time2();
	if (data->num_of_philos == 1)
		return (one_philo_case(data->philos));
	while (++i < data->num_of_philos)
	{
		pthread_mutex_lock(&data->philo_global);
		arg = &data->philos[i];
		pthread_mutex_unlock(&data->philo_global);
		if (pthread_create(&data->thread_id[i], NULL,
				thread_function, (void *)arg) != 0)
			return (0);
	}
	while (1)
	{
		i = -1;
		while (++i < data->num_of_philos)
			if (!starving_check(&data->philos[i]))
				return (-1);
	}
	return (1);
}

int	one_philo_case(t_philo *philo)
{
	printf("0 0 has taken a fork\n");
	printf("%i 1 died\n", philo->time_to_die);
	return (1);
}
