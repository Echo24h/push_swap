/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/07/06 19:00:20 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_small_min(t_p *a, t_p *b, int *count)
{
	if ((a->temp_size > 1) && (a->nbr[0] > a->nbr[1]))
		*count += command(a, b, "sa");
	else if ((a->nbr[0] > a->nbr[a->temp_size])
		|| (a->nbr[a->temp_size - 1] > a->nbr[a->temp_size]))
		*count += command(a, b, "rra");
	else if (a->nbr[0] > a->nbr[1])
		*count += command(a, b, "ra");
}

int	sort_small(t_p *a, t_p *b)
{
	int	count;
	int	temp;
	int	i_min;

	while (a->temp_size > 2)
	{
		i_min = get_miner(a, 0, a->temp_size, INT_MIN);
		push_i_atob(a, b, i_min);
	}
	count = -1;
	temp = 0;
	while (temp != count && a->temp_size > 0)
	{
		count = temp;
		sort_small_min(a, b, &temp);
	}
	while (b->temp_size >= 0)
		command(a, b, "pa");
	return (1);
}
