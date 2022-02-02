/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigbig_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:03:12 by gborne            #+#    #+#             */
/*   Updated: 2022/02/02 16:29:15 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sort_bigbig_stack(t_p *a, t_p *b)
{
	int	count;
	int	pivot;
	int	last_pivot;
	int	box_size;
	int	i;

	count = 0;
	i = 1;
	box_size = a->size / (a->size / 9);
	pivot = INT_MAX;
	last_pivot = INT_MAX;
	ft_printf("\nDEBUT : box_size :%d, pivot :%d, last_pivot :%d\n", box_size, pivot, last_pivot);
	while (box_size * i <  a->size)
	{
		pivot = find_the_pivot(a, 0, a->size, pivot);
		while (a->temp_size > a->size - (box_size * i))
		{
			ft_printf("box_size :%d, pivot :%d, last_pivot :%d", box_size, pivot, last_pivot);
			if (a->nbr[a->temp_size] > pivot && a->nbr[a->temp_size] < last_pivot)
			{
				count += command(a, b, "pb");
			}
			else
				count += command(a, b, "ra");
		}
		i++;
		sort_b_pile(a, b, &count);
		last_pivot = pivot;
	}
	ft_printf("\nFIN : box_size :%d, pivot :%d, last_pivot :%d\n", box_size, pivot, last_pivot);
	return (count);
}
