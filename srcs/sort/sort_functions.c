/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/02/02 18:00:09 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_the_bigger(t_p *p, int start, int end, int value_max)
{
	int	nb_big;
	int	i_big;

	i_big = -1;
	nb_big = INT_MIN;
	while (start <= end)
	{
		if(p->nbr[start] >= nb_big && p->nbr[start] <= value_max)
		{
			i_big = start;
			nb_big = p->nbr[start];
		}
		start++;
	}
	return (i_big);
}

int	find_the_miner(t_p *p, int start, int end, int value_min)
{
	int	nb_min;
	int	i_min;

	i_min = -1;
	nb_min = INT_MAX;
	while (start <= end)
	{
		if (p->nbr[start] <= nb_min && p->nbr[start] >= value_min)
		{
			i_min = start;
			nb_min = p->nbr[start];
		}
		start++;
	}
	return (i_min);
}

// -1 desactive le compteur
int	find_the_pivot(t_p *p, int start, int end, int count)
{
	int	i_pivot;
	int	nb_pivot;
	int	i;

	i_pivot = start;
	nb_pivot = INT_MAX;
	i = start - 1;
	while (++i <= end && count != 0)
	{
		i_pivot = find_the_bigger(p, start, end, nb_pivot - 1);
		if (i_pivot == -1)
			return (INT_MIN);
		nb_pivot = p->nbr[i_pivot];
		count--;
	}
	return (nb_pivot);
}

void	push_i_nbr_atob(t_p *a, t_p *b, int *count, int i_nbr)
{
	if (i_nbr < a->temp_size / 2)
	{
		while (i_nbr >= 0)
		{
			*count += command(a, b, "rra");
			i_nbr--;
		}
	}
	else if (i_nbr >= a->temp_size / 2)
	{
		while (i_nbr < a->temp_size)
		{
			*count += command(a, b, "ra");
			i_nbr++;
		}
	}
	*count += command(a, b, "pb");
}

void	push_i_nbr_btoa(t_p *a, t_p *b, int *count, int i_nbr)
{
	if (i_nbr < b->temp_size / 2)
	{
		while (i_nbr >= 0)
		{
			*count += command(a, b, "rrb");
			i_nbr--;
		}
	}
	else if (i_nbr >= b->temp_size / 2)
	{
		while (i_nbr < b->temp_size)
		{
			*count += command(a, b, "rb");
			i_nbr++;
		}
	}
	*count += command(a, b, "pa");
}
