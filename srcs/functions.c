/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:15:45 by gborne            #+#    #+#             */
/*   Updated: 2022/01/26 05:12:53 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_p *p)
{
	int	temp;
	temp = p->nbr[p->temp_size];
	p->nbr[p->temp_size] = p->nbr[p->temp_size - 1];
	p->nbr[p->temp_size - 1] = temp;
}

void	push(t_p *a, t_p *b)
{
	b->temp_size++;
	b->nbr[b->temp_size] = a->nbr[a->temp_size];
	a->temp_size--;
}

void	rotate(t_p *p)
{
	int	i_max;
	int	temp;

	i_max = p->temp_size;
	temp = p->nbr[i_max];
	while(i_max > 0)
	{
		p->nbr[i_max] = p->nbr[i_max - 1];
		i_max--;
	}
	p->nbr[0] = temp;
}

void	reverse_rotate(t_p *p)
{
	int	i;
	int	temp;

	i = 0;
	temp = p->nbr[0];
	while(i < p->temp_size)
	{
		p->nbr[i] = p->nbr[i + 1];
		i++;
	}
	p->nbr[p->temp_size] = temp;
}
