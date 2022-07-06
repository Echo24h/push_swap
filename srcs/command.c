/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:15:45 by gborne            #+#    #+#             */
/*   Updated: 2022/07/06 18:54:20 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_p *p)
{
	int	temp;
	temp = p->nbr[1];
	p->nbr[1] = p->nbr[0];
	p->nbr[0] = temp;
}

static void	push(t_p *src, t_p *dst)
{
	dst->temp_size++;
	shift(dst, 0);
	dst->nbr[0] = src->nbr[0];
	shift(src, 1);
	src->temp_size--;
}

static void	rotate(t_p *p)
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

static void	reverse_rotate(t_p *p)
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

int	command(t_p *a, t_p *b, char *cmd)
{
	ft_printf("%s\n", cmd);
	if (!ft_strcmp(cmd, "pa"))
		push(b, a);
	else if (!ft_strcmp(cmd, "pb"))
		push(a, b);
	else if (!ft_strcmp(cmd, "sa"))
		swap(a);
	else if (!ft_strcmp(cmd, "sb"))
		swap(b);
	else if (!ft_strcmp(cmd, "ra"))
		rotate(a);
	else if (!ft_strcmp(cmd, "rb"))
		rotate(b);
	else if (!ft_strcmp(cmd, "rra"))
		reverse_rotate(a);
	else if (!ft_strcmp(cmd, "rrb"))
		reverse_rotate(b);
	else
		return (0);
	//pile_print(*a);
	//pile_print(*b);
	return (1);
}
