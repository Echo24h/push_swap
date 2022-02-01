/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:48:52 by gborne            #+#    #+#             */
/*   Updated: 2022/02/01 05:16:13 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_nbr(char **list)
{
	int		i;
	int		j;

	i = 0;
	while (list[i])
	{
		j = 0;
		if(list[i][j] == '-' || list[i][j] == '+')
			j++;
		while (list[i][j])
		{
			if (!ft_isdigit(list[i][j]))
			{
				ft_printf("ERROR : check.c -> check_nbr()\n");
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
				ft_printf("ERROR : check.c -> check_double()\n");
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
				ft_printf("ERROR : check.c -> check_max()\n");
				return (0);
			}
		}
		else if (is_pos && ft_strlen(list[i]) > ft_strlen("2147483647"))
		{
			ft_printf("ERROR : check.c -> check_max()\n");
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
				ft_printf("ERROR : check.c -> check_min()\n");
				return (0);
			}
		}
		else if (is_neg && ft_strlen(list[i]) > ft_strlen("-2147483648"))
		{
			ft_printf("ERROR : check.c -> check_min()\n");
			return (0);
		}
		i++;
	}
	return (1);
}

char	**check_list(char **list)
{
	if (!list)
		return (NULL);
	if (check_nbr(list) && check_double(list) && check_max(list) && check_min(list))
		return (list);
	return (NULL);
}
