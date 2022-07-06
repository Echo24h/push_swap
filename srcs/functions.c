/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/07/06 19:01:06 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_bigger(t_p *p, int start, int end, int value_max)
{
	int	nb_big;
	int	i_big;

	i_big = -1;
	nb_big = INT_MIN;
	while (start <= end)
	{
		if(p->nbr[start] >= nb_big && p->nbr[start] <= value_max)
		{
			i_big = start;
			nb_big = p->nbr[start];
		}
		start++;
	}
	return (i_big);
}

int	get_miner(t_p *p, int start, int end, int value_min)
{
	int	nb_min;
	int	i_min;

	i_min = -1;
	nb_min = INT_MAX;
	while (start <= end)
	{
		if (p->nbr[start] <= nb_min && p->nbr[start] >= value_min)
		{
			i_min = start;
			nb_min = p->nbr[start];
		}
		start++;
	}
	return (i_min);
}

int	get_pivot(t_p *p, int start, int end, int margin)
{
	int	i_pivot;
	int	nb_pivot;
	int	i;

	i_pivot = start;
	nb_pivot = INT_MAX;
	i = start - 1;
	while (++i <= end && margin != 0)
	{
		i_pivot = get_bigger(p, start, end, nb_pivot - 1);
		if (i_pivot == -1)
			return (INT_MIN);
		nb_pivot = p->nbr[i_pivot];
		margin--;
	}
	return (nb_pivot);
}

void	push_i_atob(t_p *a, t_p *b, int i_nbr)
{
	if (i_nbr >= a->temp_size / 2)
		while (i_nbr++ != a->temp_size + 1)
			command(a, b, "rra");
	else if (i_nbr < a->temp_size / 2)
		while (i_nbr-- > 0)
			command(a, b, "ra");
	command(a, b, "pb");
}

void	push_i_btoa(t_p *a, t_p *b, int i_nbr)
{
	if (i_nbr >= b->temp_size / 2)
		while (i_nbr++ != b->temp_size + 1)
			command(a, b, "rrb");
	else if (i_nbr < b->temp_size / 2)
		while (i_nbr-- > 0)
			command(a, b, "rb");
	command(a, b, "pa");
}
