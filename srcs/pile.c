/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 12:15:37 by elemarch          #+#    #+#             */
/*   Updated: 2022/01/26 06:01:38 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pile_fill(t_p *pile, char **list)
{
	int	i;

	i = 1;
	while (list[i])
	{
		pile->nbr[i - 1] = ft_atoi(list[i]);
		pile->temp_size++;
		i++;
	}
}

t_p		pile_init(int size)
{
	t_p	pile;

	pile.nbr = (int*)malloc(sizeof(int) * size);
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
	pile = pile_init(size - 2);
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
