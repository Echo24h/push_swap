/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 04:18:44 by gborne            #+#    #+#             */
/*   Updated: 2022/02/02 21:38:34 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	command_p_s_r(t_p *a, t_p *b, char *cmd)
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

void	command_rr(t_p *a, t_p *b, char *cmd)
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

int	command(t_p *a, t_p *b, char *cmd)
{
	char **lst;
	int i;

	i= -1;
	lst = ft_split(cmd, ' ');
	while (lst[++i])
	{
		printf("%s\n", lst[i]);
		if (!ft_strcmp(lst[i], "rra") || !ft_strcmp(lst[i], "rrb")
			|| !ft_strcmp(lst[i], "rrr"))
			command_rr(a, b, lst[i]);
		else
			command_p_s_r(a, b, lst[i]);
		//ile_print(*a);
		//pile_print(*b);
	}
	free_list(lst);
	return (i);
}
