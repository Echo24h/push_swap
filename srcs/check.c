/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:48:52 by gborne            #+#    #+#             */
/*   Updated: 2022/07/07 16:26:05 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_nbr(char **list)
{
	int		i;
	int		j;

	i = 0;
	if (list == NULL || list[0][0] == 0)
		return (1);
	while (list[i])
	{
		j = 0;
		if (list[i][j] == '-' || list[i][j] == '+')
			j++;
		while (list[i][j])
		{
			if (!ft_isdigit(list[i][j]))
				return (write(1, "Error\nWrong number\n", 20));
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_double(char **list)
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
				return (write(1, "Error\nSimilar number\n", 22));
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_max(char **list)
{
	int	i;
	int	is_pos;

	i = 0;
	while (list[i])
	{
		is_pos = 0;
		if (list[i][0] != '-')
			is_pos = 1;
		if (is_pos && ft_strlen(list[i]) == ft_strlen("2147483647"))
		{
			if (ft_strcmp(list[i], "2147483647") > 0)
				return (write(1, "Error\ncheck.c -> check_max()\n", 30));
		}
		else if (is_pos && ft_strlen(list[i]) > ft_strlen("2147483647"))
			return (write(1, "Error\ncheck.c -> check_max()\n", 30));
		i++;
	}
	return (0);
}

static int	check_min(char **list)
{
	int	i;
	int	is_neg;

	i = 0;
	while (list[i])
	{
		is_neg = 0;
		if (list[i][0] == '-')
			is_neg = 1;
		if (is_neg && ft_strlen(list[i]) == ft_strlen("-2147483648"))
		{
			if (ft_strcmp(list[i], "-2147483647") > 0)
				return (write(1, "Error\ncheck.c -> check_min()\n", 30));
		}
		else if (is_neg && ft_strlen(list[i]) > ft_strlen("-2147483648"))
			return (write(1, "Error\ncheck.c -> check_min()\n", 30));
		i++;
	}
	return (0);
}

int	check(char **list)
{
	if (!list)
		return (0);
	if (!check_nbr(list) && !check_double(list)
		&& !check_max(list) && !check_min(list))
		return (1);
	return (0);
}
