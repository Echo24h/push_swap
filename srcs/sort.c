/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:34 by gborne            #+#    #+#             */
/*   Updated: 2022/01/29 01:54:28 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	p_command(t_p *a, t_p *b, char *command)
{
	ft_printf("%s\n", command);
	if (!ft_strcmp(command, "sa"))
		swap(a);
	else if (!ft_strcmp(command, "sb"))
		swap(b);
	else if (!ft_strcmp(command, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp(command, "pa"))
		push(b, a);
	else if (!ft_strcmp(command, "pb"))
		push(a, b);
	else if (!ft_strcmp(command, "ra"))
		rotate(a);
	else if (!ft_strcmp(command, "rb"))
		rotate(b);
	else if (!ft_strcmp(command, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(command, "rra"))
		reverse_rotate(a);
	else if (!ft_strcmp(command, "rrb"))
		reverse_rotate(b);
	else if (!ft_strcmp(command, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	pile_print(*a);
	pile_print(*b);
	return (1);
}


void	sort_pile(t_p *a, t_p *b)
{
	int	coups;

	coups = 0;
	coups += p_command(a, b, "sa");
	ft_printf("\nPile de %d nombres triée en %d coups.", a->temp_size, coups);

}
