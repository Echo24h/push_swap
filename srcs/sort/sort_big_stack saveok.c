/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:03:12 by gborne            #+#    #+#             */
/*   Updated: 2022/02/02 14:06:58 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_b_pile(t_p *a, t_p *b, int *count)
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
		i_min = find_the_miner(b, 0, b->temp_size, INT_MIN);
		i_max = find_the_bigger(b, 0, b->temp_size, INT_MAX);
		if (i_pivot - i_min < i_pivot - i_max && i_pivot - i_min < i_max)
			push_i_nbr_btoa(a, b, count, i_min);
		else
		{
			push_i_nbr_btoa(a, b, count, i_max);
			*count += command(a, b, "ra");
			i_temp--;
		}
	}
	while (--i_temp >= 0)
		*count += command(a, b, "ra");
}

int	sort_big_stack(t_p *a, t_p *b)
{
	int	count;
	int	pivot;

	count = 0;
	pivot = find_the_pivot(a, 0, a->size);
	while (a->temp_size >= a->size / 2)
	{
		if (a->nbr[a->temp_size] >= pivot)
		{
			count += command(a, b, "pb");
		}
		else
			count += command(a, b, "ra");
	}
	sort_b_pile(a, b, &count);
	pivot = a->size / 2 + (a->size % 2);
	while (a->temp_size != pivot)
		count += command(a, b, "pb");
	sort_b_pile(a, b, &count);
	return (count);
}
