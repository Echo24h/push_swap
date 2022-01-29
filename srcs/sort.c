/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/01/29 05:21:04 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_small_stack(t_p *a, t_p *b, int count)
{
	if (a->nbr[0] > a->nbr[a->temp_size])
		count += command(a, b, "ra");
	if (a->nbr[0] > a->nbr[1])
		count += command(a, b, "rra");
	if (a->nbr[a->temp_size - 1] > a->nbr[a->temp_size])
		count += command(a, b, "sa");
	return (count);
}

int	sort_big_stack(t_p *a, t_p *b, int count)
{
	count += command(a, b, "pb pb pb pb");
	return (count);
}

int	sort_pile(t_p *a, t_p *b)
{
	int	count;
	int temp;

	count = -1;
	temp = 0;
	while (temp != count)
	{
		count = temp;
		if (a->size < 5)
			temp = sort_small_stack(a, b, count);
		else
			temp = sort_big_stack(a, b, count);
	}
	return (count);
}


