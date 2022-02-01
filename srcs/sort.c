/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/02/01 05:14:55 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_the_bigger(t_p *p)
{
	int	nb_big;
	int	i;
	int	i_big;

	i = -1;
	i_big = -1;
	nb_big = -2147483648;
	while (++i <= p->temp_size)
	{
		if(p->nbr[i] >= nb_big)
		{
			i_big = i;
			nb_big = p->nbr[i];
		}
	}
	return (i_big);

}

int	sort_big_stack(t_p *a, t_p *b)
{
	int count;

	count = 0;
	count += command(a, b, "pb pb pb pb");
	return (count);
}

int	sort_pile(t_p *a, t_p *b)
{
	if (a->size < 6)
		return (sort_small_stack(a, b));
	else
		return (sort_big_stack(a, b));
}

/*
int	sort_pile(t_p *a, t_p *b)
{
	int	count;
	int temp;

	count = -1;
	temp = 0;
	while (temp != count)
	{
		count = temp;
		if (a->size < 6)
		{
			temp = sort_small_stack(a, b, count);
			while (b->temp_size >= 0)
				count += command(a, b, "pa");
		}
		else
			temp = sort_big_stack(a, b, count);
	}
	return (count);
}
*/


