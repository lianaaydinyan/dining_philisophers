/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:41:15 by liaydiny          #+#    #+#             */
/*   Updated: 2024/01/08 17:41:32 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	give_the_args_helper(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data)->num_of_philos)
	{
		(data)->philos[i].eat_count = 0;
		(data)->philos[i].left_fork = 0;
		(data)->philos[i].rigth_fork = 0;
		(data)->philos[i].global_data = data;
		(data)->philos[i].id = i;
		(data)->philos[i].last_meal = get_current_time2();
		(data)->philos[i].eaty = 'n';
		i++;
	}
}

int	give_the_args(int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	(void)ac;
	(data)->num_of_philos = ft_atoi(av[1]);
	(data)->dead_flag = 0;
	while (i < data->num_of_philos)
	{
		(data)->philos[i].time_to_die = ft_atoi(av[2]);
		(data)->philos[i].time_to_eat = ft_atoi(av[3]);
		(data)->philos[i].time_to_sleep = ft_atoi(av[4]);
		i++;
	}
	if (av[5])
		(data)->def_all_eat = ft_atoi(av[5]);
	else
		(data)->def_all_eat = -1;
	give_the_args_helper(data);
	data->program_start = get_current_time2();
	fill_the_data(data);
	create_mutex(data);
	return (1);
}

void	reach_to_num(char *str)
{
	while (*str == '0' && *(str + 1))
		str++;
}

int	parsing(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (arg_error());
	while (av[i])
	{
		if (!have_to_be_num(av[i]))
			return (0);
		i++;
	}
	i = 0;
	while (av[++i])
	{
		reach_to_num(av[i]);
		if ((ft_strlen(av[i]) < 10 && (ft_atoi(av[i])) <= 0)
			&& (ft_atoi(av[i])) >= 2147483647)
			return (have_to_be_number());
	}
	if (ft_atoi(av[1]) > 200)
		return (error_case());
	if (av[5] && ft_atoi(av[5]) <= 0)
		return (for_last_argument());
	return (1);
}
