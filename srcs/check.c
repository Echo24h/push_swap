/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:48:52 by gborne            #+#    #+#             */
/*   Updated: 2022/06/14 17:08:22 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_nbr(char **list)
{
	int		i;
	int		j;

	i = 0;
	if (list == NULL || list[0][0] == 0)
		return (0);
	while (list[i])
	{
		j = 0;
		if(list[i][j] == '-' || list[i][j] == '+')
			j++;
		while (list[i][j])
		{
			if (!ft_isdigit(list[i][j]))
			{
				write(1, "Error\nWrong number\n", 20);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double(char **list)
{
	int		i;
	int		j;

	i = 0;
	while (list[i])
	{
		j = i + 1;
		while (list[j])
		{
			if (!ft_strcmp(list[i], list[j]))
			{
				write(1, "Error\nSimilar number\n", 22);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_max(char **list)
{
	int	i;
	int	is_pos;

	i = 0;
	is_pos = 0;
	while (list[i])
	{
		if (list[i][0] != '-')
			is_pos = 1;
		if (is_pos && ft_strlen(list[i]) == ft_strlen("2147483647"))
		{
			if (ft_strcmp(list[i], "2147483647") > 0)
			{
				printf("ERROR : check.c -> check_max()\n");
				return (0);
			}
		}
		else if (is_pos && ft_strlen(list[i]) > ft_strlen("2147483647"))
		{
			printf("ERROR : check.c -> check_max()\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_min(char **list)
{
	int	i;
	int	is_neg;

	i = 0;
	is_neg = 0;
	while (list[i])
	{
		if (list[i][0] == '-')
			is_neg = 1;
		if (is_neg && ft_strlen(list[i]) == ft_strlen("-2147483648"))
		{
			if (ft_strcmp(list[i], "-2147483648") > 0)
			{
				printf("ERROR : check.c -> check_min()\n");
				return (0);
			}
		}
		else if (is_neg && ft_strlen(list[i]) > ft_strlen("-2147483648"))
		{

			printf("ERROR : check.c -> check_min()\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_list(char **list)
{
	if (!list)
		return (0);
	if (check_nbr(list) && check_double(list) && check_max(list) && check_min(list))
		return (1);
	return (0);
}
