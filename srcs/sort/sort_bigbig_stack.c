/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigbig_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:03:12 by gborne            #+#    #+#             */
/*   Updated: 2022/02/02 23:02:46 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sort_bigbig_stack(t_p *a, t_p *b, int box_size)
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
	nb_min = a->nbr[find_the_miner(a, 0, a->size, INT_MIN)];


	while (rest_sort)
	{
		sort_b_pile(a, b, &count);
		pivot = find_the_pivot(a, 0, a->size, box_size * i);
		if (pivot == INT_MIN)
			break;
		while (b->temp_size < box_size - 1)
		{
			if (pivot == nb_min && b->temp_size == a->size % box_size)
				break;
			if (a->nbr[a->temp_size] >= pivot && a->nbr[a->temp_size] < last_pivot)
			{
				count += command(a, b, "pb");
				rest_sort--;
			}
			else
				count += command(a, b, "ra");
		}
		i++;
		last_pivot = pivot;
	}

	// ont trie le reste
	i = -1;
	pivot = find_the_bigger(a, 0, a->size, INT_MAX);
	while (a->nbr[a->temp_size] != a->nbr[pivot])
		count += command(a, b, "pb");
	sort_b_pile(a, b, &count);
	//ft_printf("\nFIN : box_size :%d, last_pivot :%d\n", box_size, last_pivot);
	return (count);
}
