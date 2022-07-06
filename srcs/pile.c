/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:16 by gborne            #+#    #+#             */
/*   Updated: 2022/07/06 19:04:35 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void pile_shift(t_p *pile, int reverse)
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

static void	pile_fill(t_p *pile, char **list)
{
	int	i;

	i = 0;
	if (!list)
		return;
	while (i <= pile->size)
	{
		pile->nbr[i] = ft_atoi(list[i]);
		pile->temp_size++;
		i++;
	}
}

t_p		pile_init(int size)
{
	t_p	pile;

	pile.nbr = ft_calloc(size + 1, sizeof(int));
	pile.size = size;
	pile.temp_size = -1;
	return (pile);
}

t_p		pile_create(char **list)
{
	int	size;
	t_p	pile;

	size = 0;
	while (list[size])
		size++;
	size--;
	pile = pile_init(size);
	pile_fill(&pile, list);
	return (pile);
}

void	pile_print(t_p pile)
{
	int	i;

	i = 0;
	ft_putchar('|');
	while (i <= pile.size)
	{
		if (i <= pile.temp_size)
			ft_putnbr(pile.nbr[i]);
		else
			ft_putchar(' ');
		ft_putchar('|');
		i++;
	}
	ft_putchar('\n');
}

void	pile_destroy(t_p *pile)
{
	free(pile->nbr);
	pile->size = -1;
	pile->temp_size = -1;
}
