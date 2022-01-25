/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 12:15:37 by elemarch          #+#    #+#             */
/*   Updated: 2022/01/25 02:52:53 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pile_fill(t_p *pile, char **list)
{
	int	*tmp;
	int	i;

	i = 1;
	tmp = pile->nbr;
	while (list[i])
	{
		*tmp = ft_atoi(list[i]);
		tmp++;
		i++;
	}
}

t_p		pile_init(int size)
{
	t_p	pile;

	pile.nbr = (int*)malloc(sizeof(int) * size);
	pile.size = size;
	return (pile);
}

t_p		pile_create(char **list)
{
	int	size;
	t_p	pile;

	while (list[size])
		size++;
	pile = pile_init(size);
	pile_fill(&pile, list);
	return (pile);
}

void	pile_print(t_p pile)
{
	int	i;

	i = 0;
	while (i < pile.size)
	{
		ft_putnbr(pile.nbr[i]);
		ft_putchar('|');
		i++;
	}
	ft_putchar('\n');
}

void	pile_destroy(t_p *pile)
{
	free(pile->nbr);
	pile->size = 0;
}
