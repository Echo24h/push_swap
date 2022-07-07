/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:03:12 by gborne            #+#    #+#             */
/*   Updated: 2022/07/07 16:12:34 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_s	init_data(int nb_min, int rest_sort, int box_size)
{
	t_s	s;

	s.pivot = INT_MAX;
	s.last_pivot = INT_MAX;
	s.nb_min = nb_min;
	s.rest_sort = rest_sort;
	s.box_size = box_size;
	return (s);
}

static void	sort_b(t_p *a, t_p *b)
{
	int	i_min;
	int	i_max;
	int	i_pivot;

	i_min = 0;
	i_max = 0;
	i_pivot = 0;
	while (b->temp_size >= 0)
	{
		if (b->temp_size > 0)
			i_pivot = b->temp_size / 2;
		i_min = get_miner(b, 0, b->temp_size, INT_MIN);
		i_max = get_bigger(b, 0, b->temp_size, INT_MAX);
		if (i_pivot - i_min < i_pivot - i_max && i_pivot - i_min < i_max)
		{
			push_i_btoa(a, b, i_min);
			command(a, b, "ra");
		}
		else
			push_i_btoa(a, b, i_max);
	}
}

static void	push_range(t_s *s, t_p *a, t_p *b)
{
	while (b->temp_size < s->box_size - 1)
	{
		if (s->pivot == s->nb_min && b->temp_size == a->size % s->box_size)
			break ;
		if (a->nbr[0] >= s->pivot && a->nbr[0] < s->last_pivot)
		{
			command(a, b, "pb");
			s->rest_sort--;
		}
		else
			command(a, b, "ra");
	}
}

int	sort_big(t_p *a, t_p *b, int box_size)
{
	t_s	s;
	int	i;

	s = init_data(a->nbr[get_miner(a, 0, a->size, INT_MIN)],
			a->size + 1, box_size);
	i = 1;
	while (s.rest_sort)
	{
		sort_b(a, b);
		s.pivot = get_pivot(a, 0, a->size, s.box_size * i);
		if (s.pivot == INT_MIN)
			break ;
		push_range(&s, a, b);
		s.last_pivot = s.pivot;
		i++;
	}
	sort_b(a, b);
	while (a->nbr[0] != s.nb_min)
		command(a, b, "rra");
	return (1);
}
