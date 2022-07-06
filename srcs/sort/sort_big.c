/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:03:12 by gborne            #+#    #+#             */
/*   Updated: 2022/07/06 18:53:23 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_b(t_p *a, t_p *b)
{
	int	i_min;
	int	i_max;
	int	i_pivot;

	i_min = 0;
	i_max = 0;
	i_pivot = 0;
	while (b->temp_size >= 0)
	{
		if (b->temp_size > 0)
			i_pivot = b->temp_size / 2;
		i_min = get_miner(b, 0, b->temp_size, INT_MIN);
		i_max = get_bigger(b, 0, b->temp_size, INT_MAX);
		if (i_pivot - i_min < i_pivot - i_max && i_pivot - i_min < i_max)
		{
			push_i_btoa(a, b, i_min);
			command(a, b, "ra");
		}
		else
			push_i_btoa(a, b, i_max);
	}
}

int	sort_big(t_p *a, t_p *b, int box_size)
{
	int	pivot;
	int	last_pivot;
	int	i;
	int	rest_sort;
	int	nb_min;
	
	i = 1;
	pivot = INT_MAX;
	last_pivot = INT_MAX;
	rest_sort = a->size + 1;
	nb_min = a->nbr[get_miner(a, 0, a->size, INT_MIN)];
	while (rest_sort)
	{
		sort_b(a, b);
		pivot = get_pivot(a, 0, a->size, box_size * i);
		if (pivot == INT_MIN)
			break;
		while (b->temp_size < box_size - 1)
		{
			if (pivot == nb_min && b->temp_size == a->size % box_size)
				break;
			if (a->nbr[0] >= pivot && a->nbr[0] < last_pivot)
			{
				command(a, b, "pb");
				rest_sort--;
			}
			else
				command(a, b, "ra");
		}
		i++;
		last_pivot = pivot;
	}
	sort_b(a, b);
	while(a->nbr[0] != nb_min)
		command(a, b, "rra");
	return (1);
}
