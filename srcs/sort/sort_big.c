/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:03:12 by gborne            #+#    #+#             */
/*   Updated: 2022/07/06 16:19:58 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_b(t_p *a, t_p *b, int *count)
{
	int	i_min;
	int	i_max;
	int	i_pivot;
	int	i_temp;

	i_min = 0;
	i_max = 0;
	i_pivot = 0;
	i_temp = b->temp_size + 1;
	while (b->temp_size >= 0)
	{
		if (b->temp_size > 0)
			i_pivot = b->temp_size / 2;
		i_min = get_miner(b, 0, b->temp_size, INT_MIN);
		i_max = get_bigger(b, 0, b->temp_size, INT_MAX);
		if (i_pivot - i_min < i_pivot - i_max && i_pivot - i_min < i_max)
		{
			push_i_btoa(a, b, count, i_min);
			*count += command(a, b, "ra");
			i_temp--;
		}
		else
			push_i_btoa(a, b, count, i_max);
	}
	while (--i_temp >= -1)
		*count += command(a, b, "ra");
}

int	sort_big(t_p *a, t_p *b, int box_size)
{
	int	count;
	int	pivot;
	int	last_pivot;
	int	i;
	int	rest_sort;
	int	nb_min;

	count = 0;
	i = 1;
	pivot = INT_MAX;
	last_pivot = INT_MAX;
	rest_sort = a->size + 1;
	nb_min = a->nbr[get_miner(a, 0, a->size, INT_MIN)];


	while (rest_sort)
	{
		sort_b(a, b, &count);
		pivot = get_pivot(a, 0, a->size, box_size * i);
		if (pivot == INT_MIN)
			break;
		while (b->temp_size < box_size - 1)
		{
			if (pivot == nb_min && b->temp_size == a->size % box_size)
				break;
			if (a->nbr[0] >= pivot && a->nbr[0] < last_pivot)
			{
				count += command(a, b, "pb");
				rest_sort--;
			}
			else
				count += command(a, b, "rra");
		}
		i++;
		last_pivot = pivot;
	}

	// ont trie le reste
	i = -1;
	pivot = get_bigger(a, 0, a->size, INT_MAX);
	while (a->nbr[0] != a->nbr[pivot])
		count += command(a, b, "pb");
	sort_b(a, b, &count);
	//ft_printf("\nFIN : box_size :%d, last_pivot :%d\n", box_size, last_pivot);
	return (count);
}
