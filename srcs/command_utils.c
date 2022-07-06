/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 04:18:44 by gborne            #+#    #+#             */
/*   Updated: 2022/07/06 16:10:03 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void shift(t_p *pile, int reverse)
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

/*
static void	command_p_s_r(t_p *a, t_p *b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa"))
		push(b, a);
	else if (!ft_strcmp(cmd, "pb"))
		push(a, b);
	else if (!ft_strcmp(cmd, "sa"))
		swap(a);
	else if (!ft_strcmp(cmd, "sb"))
		swap(b);
	else if (!ft_strcmp(cmd, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp(cmd, "ra"))
		rotate(a);
	else if (!ft_strcmp(cmd, "rb"))
		rotate(b);
	else if (!ft_strcmp(cmd, "rr"))
	{
		rotate(a);
		rotate(b);
	}
}

static void	command_rr(t_p *a, t_p *b, char *cmd)
{
	if (!ft_strcmp(cmd, "rra"))
		reverse_rotate(a);
	else if (!ft_strcmp(cmd, "rrb"))
		reverse_rotate(b);
	else if (!ft_strcmp(cmd, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

static void	print_cmd(char *str)
{
	if (!ft_strcmp(str, "rra"))
		write(1, "ra\n", 4);
	else if (!ft_strcmp(str, "ra"))
		write(1, "rra\n", 5);
	else if (!ft_strcmp(str, "rrb"))
		write(1, "rb\n", 5);
	else if (!ft_strcmp(str, "rb"))
		write(1, "rrb\n", 5);
	else
		ft_printf("%s\n", str);
}

int	command(t_p *a, t_p *b, char *cmd)
{
	//print_cmd(cmd);
	ft_printf("%s\n", cmd);
	if (!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb")
		|| !ft_strcmp(cmd, "rrr"))
		command_rr(a, b, cmd);
	else
		command_p_s_r(a, b, cmd);
	//pile_print(*a);
	//pile_print(*b);
	return (1);
}

*/