/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/02/01 05:46:33 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_small_stack_min(t_p *a, t_p *b, int *count)
{
	if (a->nbr[0] > a->nbr[a->temp_size])
		*count += command(a, b, "ra");
	else if (a->nbr[0] > a->nbr[1])
		*count += command(a, b, "rra");
	else if (a->nbr[a->temp_size - 1] > a->nbr[a->temp_size])
		*count += command(a, b, "sa");
}

int	sort_small_stack(t_p *a, t_p *b)
{
	int count;
	int temp;

	count = -1;
	temp = 0;
	while (a->temp_size > 2)
		push_the_bigger(a, b, &count);
	temp = count + 1;
	while (temp != count && a->temp_size > 0)
	{
		count = temp;
		sort_small_stack_min(a, b, &temp);
	}
	while (b->temp_size >= 0)
		count += command(a, b, "pa");
	if (count == -1)
		count++;
	return (count);
}
