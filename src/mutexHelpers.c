/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexHelpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:41:05 by liaydiny          #+#    #+#             */
/*   Updated: 2024/01/08 17:41:07 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_printf(t_data *data, char *str, int a)
{
	pthread_mutex_lock(&data->print);
	if (is_dead_or_not(data))
		printf("%i %i %s", get_current_time2() - data->start_time, a, str);
	pthread_mutex_unlock(&data->print);
}

void	create_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forkk = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&data->forkk[i], NULL) != 0)
			perror("error\n");
		if (pthread_mutex_init(&data->philos[i].lock, NULL) != 0)
			perror("error\n");
		i++;
	}
	create_mutexs2(data);
}

void	create_mutexs2(t_data *data)
{
	if (pthread_mutex_init(&(data)->print, NULL) != 0)
		perror("error\n");
	if (pthread_mutex_init(&(data)->died_mtx, NULL) != 0)
		perror("error\n");
	if (pthread_mutex_init(&(data)->last_eat, NULL) != 0)
		perror("error\n");
	if (pthread_mutex_init(&(data)->philo_global, NULL) != 0)
		perror("error\n");
	if (pthread_mutex_init(&(data)->_eat, NULL) != 0)
		perror("error\n");
	if (pthread_mutex_init(&(data)->helper_dead, NULL) != 0)
		perror("error\n");
	if (pthread_mutex_init(&(data)->_fin, NULL) != 0)
		perror("error\n");
	if (pthread_mutex_init(&(data)->_fini, NULL) != 0)
		perror("error\n");
}
