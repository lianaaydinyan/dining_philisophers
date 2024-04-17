/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorManagment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:40:44 by liaydiny          #+#    #+#             */
/*   Updated: 2024/01/08 17:40:46 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	error_case(void)
{
	printf("Can't be more than 200 philos Or\n");
	return (0);
}

int	for_last_argument(void)
{
	printf("The 5th argument need to be positive\n");
	return (0);
}

int	have_to_be_number(void)
{
	printf("init invalid numbers\n");
	return (0);
}

void	allocation_error(void)
{
	printf("Allocation went wrong !\n");
	return ;
}

int	arg_error(void)
{
	printf("Wrong count of arguments\n");
	return (0);
}
