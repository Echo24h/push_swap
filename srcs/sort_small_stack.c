/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/01/29 08:27:23 by gborne           ###   ########.fr       */
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

void	push_the_bigger(t_p *a, t_p *b, int *count)
{
	int	i_big;
	int	nb_big;
	int	i;

	i = -1;
	i_big = 0;
	nb_big = -2147483648;
	while (++i <= a->temp_size)
	{
		if(a->nbr[i] > nb_big)
		{
			i_big = i;
			nb_big = a->nbr[i];
		}
	}
	if (i_big >= 0 && a->temp_size - i_big < a->temp_size / 2)
	{
		while (i_big >= 0)
		{
			*count += command(a, b, "rra");
			i_big--;
		}
	}
	else if (i_big <= a->temp_size && a->temp_size - i_big >= a->temp_size / 2)
	{
		while (i_big <= a->temp_size)
		{
			*count += command(a, b, "ra");
			i_big++;
		}
	}
	*count += command(a, b, "pb");
}

int	sort_small_stack(t_p *a, t_p *b)
{
	int count;
	int temp;

	count = 0;
	temp = 0;
	while (a->temp_size > 2)
		push_the_bigger(a, b, &count);
	temp = count - 1;
	while (temp != count)
	{
		count = temp;
		sort_small_stack_min(a, b, &temp);
	}
	count++;
	while (b->temp_size >= 0)
		count += command(a, b, "pa");
	return (count);
}
