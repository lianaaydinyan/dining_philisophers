/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:46:33 by liaydiny          #+#    #+#             */
/*   Updated: 2024/01/08 17:46:36 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <sys/time.h>
# include <assert.h>

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

struct s_philo
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				rigth_fork;
	int				left_fork;
	int				eat_count;
	int				last_meal;
	int				id;
	pthread_mutex_t	lock;
	char			eaty;
	t_data			*global_data;
};

struct s_data
{
	int				num_of_philos;
	t_philo			philos[200];
	pthread_mutex_t	print;
	pthread_mutex_t	*forkk;
	int				dead_flag;
	pthread_mutex_t	died_mtx;
	pthread_mutex_t	philo_global;
	pthread_mutex_t	helper_dead;
	pthread_mutex_t	last_eat;
	pthread_mutex_t	eat_count;
	pthread_mutex_t	_eat;
	int				start_time;
	pthread_t		thread_id[200];
	long long		program_start;
	int				already_eaty;
	int				def_all_eat;
	pthread_mutex_t	_fin;
	pthread_mutex_t	_fini;
	t_philo			*global_philos;
};

//checking
void	eaten_helper(t_philo *philo);
int		eaten(t_philo *philo);
int		starving_check(t_philo *philo);
int		starving_check(t_philo *philo);
//helpers.c
int		is_dead_or_not(t_data *data);
int		_isdigit(char c);
int		have_to_be_num(char *str);
void	fill_the_data(t_data *data);
//treadHelpers
void	philo_routine(t_philo *philo, t_data *data);
void	*thread_function(void *arg);
void	destroy_and_detach(t_data *data);
int		create_threads(t_data *data);
int		one_philo_case(t_philo *philo);
//mutexHelpers
void	philo_printf(t_data *data, char *str, int a);
void	create_mutex(t_data *data);
void	create_mutexs2(t_data *data);
//errorManagment
int		error_case(void);
int		have_to_be_number(void);
void	allocation_error(void);
int		arg_error(void);
int		for_last_argument(void);
//parsing
void	give_the_args_helper(t_data *data);
int		give_the_args(int ac, char **av, t_data *data);
int		parsing(int ac, char **av);
void	reach_to_num(char *str);
//philo.c
int		get_current_time2(void);
int		ft_usleep(int milliseconds, t_data *data);
#endif
