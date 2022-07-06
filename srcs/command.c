/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:15:45 by gborne            #+#    #+#             */
/*   Updated: 2022/07/03 13:58:33 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void shift(t_p *pile, int reverse)
{
	int	i;
	int	temp;

	if (reverse)
	{
		temp = pile->nbr[pile->temp_size];
		i = -1;
		while(++i < pile->temp_size - 1)
			pile->nbr[i] = pile->nbr[i + 1];
		pile->nbr[i] = temp;
	}
	else
	{
		i = pile->temp_size + 1;
		while(--i > 0)
			pile->nbr[i] = pile->nbr[i - 1];
	}
}

void	swap(t_p *p)
{
	int	temp;
	temp = p->nbr[1];
	p->nbr[1] = p->nbr[0];
	p->nbr[0] = temp;
}

void	push(t_p *src, t_p *dst)
{
	dst->temp_size++;
	shift(dst, 0);
	dst->nbr[0] = src->nbr[0];
	shift(src, 1);
	src->temp_size--;
}

void	rotate(t_p *p)
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

void	reverse_rotate(t_p *p)
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
