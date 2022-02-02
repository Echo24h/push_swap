/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:11:16 by gborne            #+#    #+#             */
/*   Updated: 2022/02/02 13:37:19 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pile_fill(t_p *pile, char **list)
{
	int	i;
	int i_max;

	i = 0;
	i_max = pile->size;
	if (!list)
		return;
	while (i <= pile->size)
	{
		pile->nbr[i] = ft_atoi(list[i_max]);
		pile->temp_size++;
		i_max--;
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
