/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigbig_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:03:12 by gborne            #+#    #+#             */
/*   Updated: 2022/02/02 14:18:09 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sort_bigbig_stack(t_p *a, t_p *b)
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
